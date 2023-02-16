#include <gtest/gtest.h>

#include <Account/Account.h>

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int lhs = 9;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 12);
}

TEST(FunctionsTests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 2);
}
