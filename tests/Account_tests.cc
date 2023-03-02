#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;

TEST(AccountTests, PaymentTest) {
    // Arrange
    Account account(Type::payment, "Ilya", 100, 0);
    
    // Act
    account.accrual();
    
    // Assert
    EXPECT_NEAR(account.get_balance(), 101, 0.001);
}


