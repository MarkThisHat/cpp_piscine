#include <gtest/gtest.h>
#include "../ex01/Fixed.hpp"

TEST(FixedTest, DefaultConstructor) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
}

TEST(FixedTest, CopyConstructor) {
    Fixed a;
    a.setRawBits(42);
    Fixed b(a);
    EXPECT_EQ(b.getRawBits(), 42);
}

TEST(FixedTest, CopyAssignmentOperator) {
    Fixed a;
    a.setRawBits(42);
    Fixed b;
    b = a;
    EXPECT_EQ(b.getRawBits(), 42);
}

TEST(FixedTest, SetAndGetRawBits) {
    Fixed a;
    a.setRawBits(42);
    EXPECT_EQ(a.getRawBits(), 42);
}

TEST(FixedTest, IntConstructor) {
    Fixed a(42);
    EXPECT_EQ(a.getRawBits(), 42 << 8);
    EXPECT_EQ(a.toInt(), 42);
}

TEST(FixedTest, FloatConstructor) {
    Fixed a(42.42f);
    EXPECT_NEAR(a.toFloat(), 42.42f, 0.01);
}

TEST(FixedTest, ToFloatAndToInt) {
    Fixed a(42.42f);
    EXPECT_NEAR(a.toFloat(), 42.42f, 0.01);
    EXPECT_EQ(a.toInt(), 42);
}


TEST(FixedTest, InsertionOperator) {
    Fixed a(42.42f);
    std::ostringstream oss;
    oss << a;
    EXPECT_EQ(oss.str(), "42.4219");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
