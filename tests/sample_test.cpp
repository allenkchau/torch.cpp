#include <gtest/gtest.h>

// A dummy function to simulate production code
int Add(int a, int b) {
    return a + b;
}

// TEST(TestSuiteName, TestName)
TEST(MathFunctions, AddTwoPositiveNumbers) {
    EXPECT_EQ(Add(2, 3), 5); // Asserts that 2 + 3 equals 5
}

TEST(MathFunctions, AddNegativeNumbers) {
    EXPECT_EQ(Add(-1, -1), -2);
}
