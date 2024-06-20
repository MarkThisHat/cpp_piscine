#include <gtest/gtest.h>
#include "../ex02/Fixed.hpp"

TEST(FixedTest, DefaultConstructor) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
}

TEST(FixedTest, IntConstructor) {
    Fixed a(5);
    EXPECT_EQ(a.getRawBits(), 5 << 8);
    EXPECT_EQ(a.toInt(), 5);
}

TEST(FixedTest, FloatConstructor) {
    Fixed a(5.05f);
    EXPECT_NEAR(a.toFloat(), 5.05f, 0.01);
}

TEST(FixedTest, CopyConstructor) {
    Fixed a(5.05f);
    Fixed b(a);
    EXPECT_NEAR(b.toFloat(), 5.05f, 0.01);
}

TEST(FixedTest, AssignmentOperator) {
    Fixed a(5.05f);
    Fixed b;
    b = a;
    EXPECT_NEAR(b.toFloat(), 5.05f, 0.01);
}

TEST(FixedTest, ComparisonOperators) {
    Fixed a(5.05f);
    Fixed b(2.5f);
    EXPECT_TRUE(a > b);
    EXPECT_TRUE(b < a);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(b <= a);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

TEST(FixedTest, ArithmeticOperators) {
    Fixed a(5.05f);
    Fixed b(2);
    Fixed c = a + b;
    Fixed d = a - b;
    Fixed e = a * b;
    Fixed f = a / b;
    EXPECT_NEAR(c.toFloat(), 7.05f, 0.01);
    EXPECT_NEAR(d.toFloat(), 3.05f, 0.01);
    EXPECT_NEAR(e.toFloat(), 10.1f, 0.01);
    EXPECT_NEAR(f.toFloat(), 2.525f, 0.01);
}

TEST(FixedTest, IncrementDecrementOperators) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
    EXPECT_EQ((++a).getRawBits(), 1);
    EXPECT_EQ(a.getRawBits(), 1);
    EXPECT_EQ((a++).getRawBits(), 1);
    EXPECT_EQ(a.getRawBits(), 2);
    EXPECT_EQ((--a).getRawBits(), 1);
    EXPECT_EQ(a.getRawBits(), 1);
    EXPECT_EQ((a--).getRawBits(), 1);
    EXPECT_EQ(a.getRawBits(), 0);
}

TEST(FixedTest, MinMaxFunctions) {
    Fixed a(5.05f);
    Fixed b(2.5f);
    EXPECT_EQ(Fixed::min(a, b), b);
    EXPECT_EQ(Fixed::max(a, b), a);

    const Fixed c(3.14f);
    const Fixed d(6.28f);
    EXPECT_EQ(Fixed::min(c, d), c);
    EXPECT_EQ(Fixed::max(c, d), d);
}

TEST(FixedTest, OutputOperator) {
    Fixed a(5.05f);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "5.05078");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
