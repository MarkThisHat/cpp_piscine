#include <gtest/gtest.h>
#include "../ex00/Fixed.hpp"

// Test default constructor
TEST(FixedTest, DefaultConstructor) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
}

// Test copy constructor
TEST(FixedTest, CopyConstructor) {
    Fixed a;
    a.setRawBits(42);
    Fixed b(a);
    EXPECT_EQ(b.getRawBits(), 42);
}

// Test copy assignment operator
TEST(FixedTest, CopyAssignmentOperator) {
    Fixed a;
    a.setRawBits(42);
    Fixed b;
    b = a;
    EXPECT_EQ(b.getRawBits(), 42);
}

// Test setRawBits and getRawBits
TEST(FixedTest, SetAndGetRawBits) {
    Fixed a;
    a.setRawBits(42);
    EXPECT_EQ(a.getRawBits(), 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
