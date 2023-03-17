#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(UsersTests, SizeTest) {
	// Arrange
	Users accounts;

	
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });
	
	// Assert
	EXPECT_EQ(accounts.get_size(), 4);
}

TEST(UsersTests, IndexOfMaxBalance) {
	// Arrange
	Users accounts;
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	int index = accounts.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(UsersTests, InsertThrowTest) {
	// Arrange
	Users accounts;
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	int index = accounts.index_of_max_balance();

	// Assert
	ASSERT_ANY_THROW(accounts.insert({ credit, "Lera" , -250, 1 }, 15));
	ASSERT_ANY_THROW(accounts.insert({ deposit, "Vanya", 6000, 2 }, 5));
	ASSERT_NO_THROW(accounts.insert({ payment, "Ksenia", 2000, 0 }, 2));
}

TEST(UsersTests, RemoveThrowTest) {
	// Arrange
	Users accounts;

	// Act
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Assert
	ASSERT_ANY_THROW(accounts.remove(5));
	ASSERT_NO_THROW(accounts.remove(2));
}

TEST(UsersTests, AddThrowTest) {
	// Arrange
	Users accounts;

	// Act
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });	

	// Assert
	ASSERT_ANY_THROW(accounts.add({ credit, "Lera" , -250, 1 }));
	
	accounts.remove(2);
	accounts.remove(3);

	ASSERT_NO_THROW(accounts.add({ deposit, "Vanya", 6000, 2 }));

}



TEST(UsersTests, Get_Item_ThrowTest) {
	// Arrange
	Users accounts;
	// Act

	// Assert
	ASSERT_ANY_THROW(accounts.get_item(0));
}

TEST(UsersTests, AccrualListTest) {
	// Arrange
	Users accounts;
	accounts.add({ deposit, "Ilya", 3500, 12 });
	accounts.add({ credit, "Andrew", -120, 24.9 });
	accounts.add({ deposit, "Polina", 95500, 7.8 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act	
	for (int i = 0; i < accounts.get_size(); ++i) {
		accounts[i].accrual();
	}
	int index = accounts.index_of_max_balance();

	// Assert
	ASSERT_EQ(index, 2);
}

TEST(UsersTests, Get_ItemTest) {
	// Arrange
	Users accounts;
	accounts.add({ payment, "Ilya", 3500, 0 });
	accounts.add({ payment, "Andrew", 120, 0 });
	accounts.add({ payment, "Polina", 95500, 0 });
	accounts.add({ payment, "Oksana", 7550, 0 });

	// Act
	Account index = accounts.get_item(3);

	// Assert
	ASSERT_EQ(index.get_balance(), 7550);
}