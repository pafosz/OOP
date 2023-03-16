#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest) {
	// Arrange
	Account account(AccountType::payment, "Ilya Mantrov", 1000, 0);	

	// Act
	std::string a1 = account.get_type();
	float a2 = account.get_percent();
	std::string a3 = account.get_name();
	float a4 = account.get_balance();

	// Assert
	EXPECT_EQ(a1, "Payment");
	EXPECT_EQ(a2, 0);
	EXPECT_EQ(a3, "Ilya Mantrov");
	EXPECT_NEAR(a4, 1000, 0.001);
}

TEST(AccountTests, DepositTest) {
	// Arrange
	Account account(AccountType::deposit, "Ilya Mantrov", 1000, 12);

	// Act
	std::string a1 = account.get_type();
	float a2 = account.get_percent();
	std::string a3 = account.get_name();
	float a4 = account.get_balance();

	// Assert
	EXPECT_EQ(a1, "Deposit");
	EXPECT_EQ(a2, 0);
	EXPECT_EQ(a3, "Ilya Mantrov");
	EXPECT_NEAR(a4, 1000, 0.001);
}

TEST(AccountTests, DepositTest2) {
	// Arrange
	Account account(AccountType::deposit, "Ilya Mantrov", 1000, 10.4);

	// Act
	float a1 = account.get_percent();

	// Assert
	EXPECT_NEAR(a1, 10.4, 0.001);
}

TEST(AccountTests, PaymentTest2) {
	// Arrange
	Account account(AccountType::payment, "Ilya Mantrov", 1000, 10.4);

	// Act
	std::string a1 = account.get_type();

	// Assert
	EXPECT_EQ(a1, "Payment");
}

TEST(AccountTests, DepositTest3) {
	// Arrange
	Account account(AccountType::deposit, "Ilya Mantrov", 1000, 5);
	Account account2(AccountType::deposit, "Ilya Mantrov", 500, 1);

	// Act
	account.accrual();
	account2.accrual();

	// Assert
	EXPECT_NEAR(account.get_balance(), 1004.166, 0.001);
	EXPECT_NEAR(account2.get_balance(), 500.416, 0.001);
}

TEST(AccountTests, CreditTest1) {
	// Arrange
	Account account(AccountType::credit, "Ilya Mantrov", -1000, 10);

	// Act
	account.accrual();

	// Assert
	EXPECT_NEAR(account.get_balance(), -1008.333, 0.001);
}







