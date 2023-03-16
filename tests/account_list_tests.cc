#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(UsersTests, SizeTest) {
	// Arrange
	Users user_size(8);

	// Assert
	EXPECT_EQ(user_size.get_size(), 8);
}

TEST(UsersTests, IndexOfMaxBalance) {
	// Arrange
	Users accounts(0);
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	int index = accounts.index_of_max_balance(accounts);

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(UsersTests, InsertTest) {
	// Arrange
	Users accounts(0);
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	int index = accounts.index_of_max_balance(accounts);

	// Assert
	ASSERT_ANY_THROW(accounts.insert({ credit, "Lera" , -8, 1 }, 15));
}

TEST(UsersTests, RemoveZeroIndexTest) {
	// Arrange
	Users accounts(0);

	// Act

	// Assert
	ASSERT_ANY_THROW(accounts.remove(0));
}

TEST(UsersTests, Get_Item_ThrowTest) {
	// Arrange
	Users accounts(0);
	// Act

	// Assert
	ASSERT_ANY_THROW(accounts.get_item(0));
}

TEST(UsersTests, Test) {
	// Arrange
	Users accounts(0);
	accounts.add({ deposit, "Ilya", 3500, 12 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	int index = accounts[0].accrual();

	// Assert
	ASSERT_EQ(index, 3535);
}

TEST(UsersTests, Get_ItemTest) {
	// Arrange
	Users accounts(0);
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	Account index = accounts.get_item(3);

	// Assert
	ASSERT_EQ(index.get_balance(), 7550);
}