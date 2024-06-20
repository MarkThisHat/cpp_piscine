#include <gtest/gtest.h>
#include "../ex03/bsp.hpp"

TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_EQ(p.getX().toFloat(), 0.0f);
    EXPECT_EQ(p.getY().toFloat(), 0.0f);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(3.5f, 4.2f);
    EXPECT_NEAR(p.getX().toFloat(), 3.5f, 0.001);
    EXPECT_NEAR(p.getY().toFloat(), 4.2f, 0.001);
}

TEST(PointTest, CopyConstructor) {
    Point p1(3.5f, 4.2f);
    Point p2(p1);
    EXPECT_NEAR(p2.getX().toFloat(), 3.5f, 0.001);
    EXPECT_NEAR(p2.getY().toFloat(), 4.2f, 0.001);
}

TEST(PointTest, AssignmentOperator) {
    Point p1(3.5f, 4.2f);
    Point p2;
    p2 = p1;
    EXPECT_NEAR(p2.getX().toFloat(), 3.5f, 0.001);
    EXPECT_NEAR(p2.getY().toFloat(), 4.2f, 0.001);
}

TEST(BSPTest, PointInsideTriangle) {
    Point a(0.0f, 0.0f), b(5.0f, 0.0f), c(2.5f, 5.0f);
    Point p(2.5f, 2.0f);
    EXPECT_TRUE(bsp(a, b, c, p));
}

TEST(BSPTest, PointOutsideTriangle) {
    Point a(0.0f, 0.0f), b(5.0f, 0.0f), c(2.5f, 5.0f);
    Point p(5.0f, 5.0f);
    EXPECT_FALSE(bsp(a, b, c, p));
}

TEST(BSPTest, PointOnEdge) {
    Point a(0.0f, 0.0f), b(5.0f, 0.0f), c(2.5f, 5.0f);
    Point p(2.5f, 0.0f);
    EXPECT_FALSE(bsp(a, b, c, p));
}

TEST(BSPTest, PointOnVertex) {
    Point a(0.0f, 0.0f), b(5.0f, 0.0f), c(2.5f, 5.0f);
    Point p(0.0f, 0.0f);
    EXPECT_FALSE(bsp(a, b, c, p));
}
