#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest) {
	// Arrange
	Account account(AccountType::payment, "Ilya Mantrov", 1000, 0);	

	// Act
	std::string type = account.get_type();
	float percent = account.get_percent();
	std::string name = account.get_name();
	float balance = account.get_balance();
	float accrual = account.accrual();

	// Assert	
	EXPECT_EQ(type, "Payment");
	EXPECT_EQ(percent, 0);
	EXPECT_EQ(name, "Ilya Mantrov");
	EXPECT_NEAR(balance, 1000, 0.001);
	EXPECT_NEAR(accrual, 1000, 0.001);
}

TEST(AccountTests, DepositTest) {
	// Arrange
	Account account(AccountType::deposit, "Ilya Mantrov", 5000, 12);

	// Act
	std::string type = account.get_type();
	float percent = account.get_percent();
	std::string name = account.get_name();
	float balance = account.get_balance();
	float accrual = account.accrual();

	// Assert
	EXPECT_EQ(type, "Deposit");
	EXPECT_EQ(percent, 12);
	EXPECT_EQ(name, "Ilya Mantrov");
	EXPECT_NEAR(balance, 5000, 0.001);
	EXPECT_NEAR(accrual, 5050, 0.001);
}

TEST(AccountTests, CreditTest) {
	// Arrange
	Account account(AccountType::credit, "Ilya Mantrov", -12000, 10.4f);

	// Act
	std::string type = account.get_type();
	float percent = account.get_percent();
	std::string name = account.get_name();
	float balance = account.get_balance();
	float accrual = account.accrual();

	// Assert
	EXPECT_EQ(type, "Credit");
	EXPECT_EQ(percent, 10.4f);
	EXPECT_EQ(name, "Ilya Mantrov");
	EXPECT_NEAR(balance, -12000, 0.001);
	EXPECT_NEAR(accrual, -12104, 0.001);
}








