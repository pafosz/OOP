#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest) {
	// Arrange
	
	std::shared_ptr<Payment>account1(std::make_shared<Payment>("Ilya", 1000.0f));
		
	// Act		
	std::string name = account1->get_name();
	float balance = account1->get_balance();
	float accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, 1000, 0.001);
	EXPECT_NEAR(accrual, 1000, 0.001);
}

TEST(AccountTests, DepositTest) {
	// Arrange
	std::shared_ptr<Deposit>account1(std::make_shared<Deposit>("Ilya", 1000.0f, 2.0f));

	// Act
	
	float percent = account1->get_percent();
	std::string name = account1->get_name();
	float balance = account1->get_balance();
	float accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(percent, 2.0f);
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, 1000, 0.001);
	EXPECT_NEAR(accrual, 1020, 0.001);
}

TEST(AccountTests, CreditTest) {
	// Arrange
	std::shared_ptr<Credit>account1(std::make_shared<Credit>("Ilya", -1000.0f, 2.0f));

	// Act	
	float percent = account1->get_percent();
	std::string name = account1->get_name();
	float balance = account1->get_balance();
	float accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(percent, 2.0f);
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, -1000, 0.001);
	EXPECT_NEAR(accrual, -1020, 0.001);
}








