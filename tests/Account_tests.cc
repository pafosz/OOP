#include <gtest/gtest.h>

#include <account/account.h>

using namespace account;


TEST(AccountTests, PaymentTest1) {
    // Arrange
    Account account(Type::payment, "Ilya Mantrov", 1000, 0);
    Account account1(Type::payment, "Ilya Mantrov", 555, 0);
    
    // Act
    float a1 = account.get_balance();
    float a2 = account1.get_balance();
    
    // Assert
    EXPECT_NEAR(a1, 1000, 0.001);
    EXPECT_NEAR(a2, 555, 0.001);
}

TEST(AccountTests, DepositTest1) {
    // Arrange
    Account account(Type::deposit, "Ilya Mantrov", 1000, 0);

    // Act
    std::string a1 = account.get_name();

    // Assert
    EXPECT_EQ(a1, "Ilya Mantrov");
}

TEST(AccountTests, DepositTest2) {
    // Arrange
    Account account(Type::deposit, "Ilya Mantrov", 1000, 10.4);

    // Act
    float a1 = account.get_percent();

    // Assert
    EXPECT_NEAR(a1, 10.4, 0.001);
}

TEST(AccountTests, PaymentTest2) {
    // Arrange
    Account account(Type::payment, "Ilya Mantrov", 1000, 10.4);

    // Act
     std::string a1 = account.get_type();

    // Assert
    EXPECT_EQ(a1, "Payment");
}

TEST(AccountTests, DepositTest3) {
    // Arrange
    Account account(Type::deposit, "Ilya Mantrov", 1000, 5);
    Account account2(Type::deposit, "Ilya Mantrov", 500, 1);

    // Act
    account.accrual();  
    account2.accrual();

    // Assert
    EXPECT_NEAR(account.get_balance(), 1004.166, 0.001);
    EXPECT_NEAR(account2.get_balance(), 500.416, 0.001);
}

TEST(AccountTests, CreditTest1) {
    // Arrange
    Account account(Type::credit, "Ilya Mantrov", -1000, 10);

    // Act
    account.accrual();

    // Assert
    EXPECT_NEAR(account.get_balance(), -1008.333, 0.001);
}

//TEST(AccountTests, CreditTest2) {
//    // Arrange
//    Account account(Type::credit, "Ilya Mantrov", 1000, 10);
//
//    // Act
//    account.accrual();
//
//    // Assert
//    EXPECT_NEAR(account.get_balance(), 1008.333, 0.001); //специальная ошибка(кредит не может быть > 0)
//}

TEST(UsersTests, SizeTest) {
    // Arrange
    Users user_size(8);

    // Assert
    EXPECT_EQ(user_size.get_size(), 8);
}

//TEST(UsersTests, CapacityCheck) {
//    // Arrange
//    Users accounts();
//    
//
//    // Act
//    account.accrual();
//
//    // Assert
//    EXPECT_NEAR(account.get_balance(), -1008.333, 0.001);
//}




