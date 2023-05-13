#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;

std::shared_ptr<Payment>acc1(std::make_shared<Payment>("Ilya", 3500));
std::shared_ptr<Deposit>acc2(std::make_shared<Deposit>("Andrew", 120, 2));
std::shared_ptr<Credit>acc3(std::make_shared<Credit>("Polina", 95500, 1));
std::shared_ptr<Deposit>acc4(std::make_shared<Deposit>("Oksana", 7550, 1.2));
std::shared_ptr<Credit>acc5(std::make_shared<Credit>("Lera", -250, 1));
std::shared_ptr<Deposit>acc6(std::make_shared<Deposit>("Vanya", 6000, 2));

TEST(AccountListTests, SizeTest) {
	// Arrange
	AccountList list;
	
	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);

	// Assert
	EXPECT_EQ(list.get_size(), 4);
}

TEST(AccountListTests, IndexOfMaxBalance) {
	// Arrange
	AccountList list;	

	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);
	int index = list.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(AccountListTests, InsertThrowTest) {
	// Arrange
	AccountList list;

	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);
	
	// Assert	
	ASSERT_ANY_THROW(list.insert(acc5, 5));
	ASSERT_NO_THROW(list.insert(acc5, 2));
}

TEST(AccountListTests, RemoveThrowTest) {
	// Arrange
	AccountList list;

	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);

	// Assert
	ASSERT_ANY_THROW(list.remove(5));
	ASSERT_NO_THROW(list.remove(2));
	EXPECT_EQ(list[2]->get_balance(), 7550);
}

TEST(AccountListTests, AddThrowTest) {
	// Arrange
	AccountList list;

	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);
	list.add(acc5);
	list.add(acc6);
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	
	// Assert
	list.remove(2);
	list.remove(3);

	ASSERT_NO_THROW(list.add(acc5));
}

TEST(AccountListTests, AccrualListTest) {
	// Arrange
	AccountList list;

	// Act
	list.add(acc1);
	list.add(acc2);
	list.add(acc3);
	list.add(acc4);

	for (int i = 0; i < list.get_size(); ++i) {
		list[i]->accrual();
	}
	int index = list.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}