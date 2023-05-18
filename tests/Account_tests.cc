#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest) {
	// Arrange
	
	std::shared_ptr<Payment>account1(std::make_shared<Payment>("Ilya", 1000.0));
		
	// Act		
	std::string name = account1->get_name();
	double balance = account1->get_balance();
	double accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, 1000, 0.001);
	EXPECT_NEAR(accrual, 1000, 0.001);
}

TEST(AccountTests, DepositTest) {
	// Arrange
	std::shared_ptr<Deposit>account1(std::make_shared<Deposit>("Ilya", 1000, 2.0));

	// Act
	
	double percent = account1->get_percent();
	std::string name = account1->get_name();
	double balance = account1->get_balance();
	double accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(percent, 2);
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, 1000, 0.001);
	EXPECT_NEAR(accrual, 1020, 0.001);
}

TEST(AccountTests, CreditTest) {
	// Arrange
	std::shared_ptr<Credit>account1(std::make_shared<Credit>("Ilya", -1000, 2));

	// Act	
	double percent = account1->get_percent();
	std::string name = account1->get_name();
	double balance = account1->get_balance();
	double accrual = account1->accrual();

	// Assert	
	EXPECT_EQ(percent, 2);
	EXPECT_EQ(name, "Ilya");
	EXPECT_NEAR(balance, -1000, 0.001);
	EXPECT_NEAR(accrual, -1020, 0.001);
}








