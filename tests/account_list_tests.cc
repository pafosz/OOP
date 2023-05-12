#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;

Payment User1 = { payment, "Ilya", 3500, 0 };
Account User2 = { deposit, "Andrew", 120, 2 };
Account User3 = { credit, "Polina", 95500, 1 };
Account User4 = { deposit, "Oksana", 7550, 1.2 };
Account User5 = { credit, "Lera" , -250, 1 };
Account User6 = { deposit, "Vanya", 6000, 2 };


TEST(AccountListTests, SizeTest) {
	// Arrange
	AccountList accounts;
	
	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);

	// Assert
	EXPECT_EQ(accounts.get_size(), 4);
}

TEST(AccountListTests, IndexOfMaxBalance) {
	// Arrange
	AccountList accounts;	

	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);
	int index = accounts.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(AccountListTests, InsertThrowTest) {
	// Arrange
	AccountList accounts;

	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);
	//int index = accounts.index_of_max_balance();

	// Assert
	
	ASSERT_ANY_THROW(accounts.insert(User5, 5));
	ASSERT_NO_THROW(accounts.insert(User5, 2));

}

TEST(AccountListTests, RemoveThrowTest) {
	// Arrange
	AccountList accounts;

	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);

	// Assert
	ASSERT_ANY_THROW(accounts.remove(5));
	ASSERT_NO_THROW(accounts.remove(2));
	EXPECT_EQ(accounts[2].get_balance(), 7550);
}

TEST(AccountListTests, AddThrowTest) {
	// Arrange
	AccountList accounts;

	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);
	accounts.add(User5);
	accounts.add(User6);
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	

	// Assert
	

	accounts.remove(2);
	accounts.remove(3);

	ASSERT_NO_THROW(accounts.add(User5));

}

TEST(AccountListTests, Get_Item_ThrowTest) {
	// Arrange
	AccountList accounts;
	// Act

	// Assert
	ASSERT_ANY_THROW(accounts.get_item(0));
}

TEST(AccountListTests, AccrualListTest) {
	// Arrange
	AccountList accounts;
	

	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);

	for (int i = 0; i < accounts.get_size(); ++i) {
		accounts[i].accrual();
	}
	int index = accounts.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(AccountListTests, Get_ItemTest) {
	// Arrange
	AccountList accounts;
	
	// Act
	accounts.add(User1);
	accounts.add(User2);
	accounts.add(User3);
	accounts.add(User4);

	Account index = accounts.get_item(3);

	// Assert
	ASSERT_EQ(index.get_balance(), 7550);
}