// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPS = 1e-12;

TEST(CircleTest, ConstructorPositiveRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 5.0 * 5.0);
}

TEST(CircleTest, ConstructorZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeRadiusThrows) {
    EXPECT_THROW(Circle(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusMethod) {
    Circle c(1.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 7.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 7.0 * 7.0);
}

TEST(CircleTest, SetRadiusNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceMethod) {
    Circle c(1.0);
    c.setFerence(2 * PI * 3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 3.0);
    EXPECT_NEAR(c.getArea(), PI * 3.0 * 3.0, EPS);
}

TEST(CircleTest, SetAreaMethod) {
    Circle c(1.0);
    c.setArea(PI * 4.0 * 4.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 4.0 * 4.0, EPS);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-5.0), std::invalid_argument);
}

TEST(CircleTest, LargeRadiusValue) {
    Circle c(1000.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1000.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1000.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 1000.0 * 1000.0);
}

TEST(CircleTest, SmallRadiusValue) {
    Circle c(0.001);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.001);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 0.001, EPS);
    EXPECT_NEAR(c.getArea(), PI * 0.001 * 0.001, EPS);
}

TEST(PoolCostTest, BasicPoolCalculation) {
    double totalCost = calcPoolBorderCost(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(totalCost, 72256.63, 0.1);
}

TEST(PoolCostTest, ZeroPathWidth) {
    double totalCost = calcPoolBorderCost(5.0, 0.0, 1000.0, 2000.0);
    EXPECT_NEAR(totalCost, 62831.85, 0.1);
}

TEST(PoolCostTest, ZeroPoolRadius) {
    double total_cost = calcPoolBorderCost(0.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(total_cost, 15707.96, 0.1);
}

TEST(PoolCostTest, HighCostMaterials) {
    double totalCost = calcPoolBorderCost(2.0, 0.5, 5000.0, 10000.0);
    EXPECT_NEAR(totalCost, 192422.55, 0.1);
}

TEST(PoolCostTest, RadiusEqualsPathWidth) {
    double totalCost = calcPoolBorderCost(1.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(totalCost, 34557.52, 0.1);
}

TEST(GapTest, ZeroAddedLength) {
    double gap = calcGap(5.0, 0.0);
    EXPECT_NEAR(gap, 0.0, 1e-12);
}

TEST(GapTest, SmallEarthRadius) {
    double gap = calcGap(1.0, 0.1);
    EXPECT_NEAR(gap, 0.015915494309189535, 1e-12);
}

TEST(GapTest, EarthAndRopeClassic) {
    double earthRadius = 6371000.0;  
    double addedLength = 1.0;  
    double gap = calcGap(earthRadius, addedLength);
    EXPECT_NEAR(gap, 0.15915494309189535, 1e-6);
}

TEST(GapTest, NegativeAddedLength) {
    double gap = calcGap(5.0, -0.1);
    EXPECT_NEAR(gap, -0.015915494309189535, 1e-12);
}

TEST(GapTest, ZeroEarthRadius) {
    double gap = calcGap(0.0, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-12);
}