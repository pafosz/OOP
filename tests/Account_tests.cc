#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest1) {
    // Arrange
    Account account(Type::payment, "Ilya Mantrov", 1000, 0);
    
    // Act
    float a1 = account.get_balance();
    
    // Assert
    EXPECT_NEAR(a1, 1000, 0.001);
}

TEST(AccountTests, PaymentTest2) {
    // Arrange
    Account account(Type::deposit, "Ilya Mantrov", 1000, 0);

    // Act
    std::string a1 = account.get_name();

    // Assert
    EXPECT_EQ(a1, "Ilya Mantrov");
}

TEST(AccountTests, PaymentTest3) {
    // Arrange
    Account account(Type::deposit, "Ilya Mantrov", 1000, 10.4);

    // Act
    float a1 = account.get_percent();

    // Assert
    EXPECT_NEAR(a1, 10.4, 0.001);
}

TEST(AccountTests, PaymentTest4) {
    // Arrange
    Account account(Type::payment, "Ilya Mantrov", 1000, 10.4);

    // Act
     std::string a1 = account.get_type();

    // Assert
    EXPECT_EQ(a1, "Payment");
}





