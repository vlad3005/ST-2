// Copyright 2026 UNN-CS
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"
#include <cmath>

const double LOCAL_PI = std::acos(-1.0);

// Group 1: Circle Constructor
TEST(CircleInit, CanCreateCircle) {
    Circle c(10.0);
    EXPECT_DOUBLE_EQ(10.0, c.getRadius());
}

TEST(CircleInit, ConstructorComputesFerence) {
    Circle c(10.0);
    EXPECT_NEAR(20.0 * LOCAL_PI, c.getFerence(), 1e-5);
}

TEST(CircleInit, ConstructorComputesArea) {
    Circle c(10.0);
    EXPECT_NEAR(100.0 * LOCAL_PI, c.getArea(), 1e-5);
}

TEST(CircleInit, ZeroRadiusIsHandled) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

// Group 2: Circle Setters and Getters for Radius
TEST(CircleMutator, RadiusUpdateChangesRadius) {
    Circle c(5.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(7.0, c.getRadius());
}

TEST(CircleMutator, RadiusUpdateChangesFerence) {
    Circle c(5.0);
    c.setRadius(7.0);
    EXPECT_NEAR(14.0 * LOCAL_PI, c.getFerence(), 1e-5);
}

TEST(CircleMutator, RadiusUpdateChangesArea) {
    Circle c(5.0);
    c.setRadius(7.0);
    EXPECT_NEAR(49.0 * LOCAL_PI, c.getArea(), 1e-5);
}

// Group 3: Circle Setters and Getters for Ference
TEST(CircleMutator, FerenceUpdateChangesFerence) {
    Circle c(5.0);
    c.setFerence(10.0 * LOCAL_PI);
    EXPECT_DOUBLE_EQ(10.0 * LOCAL_PI, c.getFerence());
}

TEST(CircleMutator, FerenceUpdateChangesRadius) {
    Circle c(5.0);
    c.setFerence(10.0 * LOCAL_PI);
    EXPECT_NEAR(5.0, c.getRadius(), 1e-5);
}

TEST(CircleMutator, FerenceUpdateChangesArea) {
    Circle c(5.0);
    c.setFerence(10.0 * LOCAL_PI);
    EXPECT_NEAR(25.0 * LOCAL_PI, c.getArea(), 1e-5);
}

// Group 4: Circle Setters and Getters for Area
TEST(CircleMutator, AreaUpdateChangesArea) {
    Circle c(5.0);
    c.setArea(100.0 * LOCAL_PI);
    EXPECT_DOUBLE_EQ(100.0 * LOCAL_PI, c.getArea());
}

TEST(CircleMutator, AreaUpdateChangesRadius) {
    Circle c(5.0);
    c.setArea(100.0 * LOCAL_PI);
    EXPECT_NEAR(10.0, c.getRadius(), 1e-5);
}

TEST(CircleMutator, AreaUpdateChangesFerence) {
    Circle c(5.0);
    c.setArea(100.0 * LOCAL_PI);
    EXPECT_NEAR(20.0 * LOCAL_PI, c.getFerence(), 1e-5);
}

// Group 5: Complex mutation chains
TEST(CircleChain, RadiusToAreaToFerence) {
    Circle c(2.0);
    c.setArea(16.0 * LOCAL_PI);
    EXPECT_NEAR(4.0, c.getRadius(), 1e-5);
    c.setFerence(20.0 * LOCAL_PI);
    EXPECT_NEAR(10.0, c.getRadius(), 1e-5);
    EXPECT_NEAR(100.0 * LOCAL_PI, c.getArea(), 1e-5);
}

TEST(CircleChain, DoubleUpdateRadius) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(3.0, c.getRadius());
    EXPECT_NEAR(6.0 * LOCAL_PI, c.getFerence(), 1e-5);
}

// Group 6: Tasks - Earth and Rope
TEST(EarthAndRopeTask, DefaultCase) {
    double r = 6378100.0;
    double gap = calculateEarthRopeGap(r, 1.0);
    EXPECT_NEAR(1.0 / (2.0 * LOCAL_PI), gap, 1e-5);
}

TEST(EarthAndRopeTask, SmallRadiusCase) {
    double r = 10.0;
    double gap = calculateEarthRopeGap(r, 1.0);
    EXPECT_NEAR(1.0 / (2.0 * LOCAL_PI), gap, 1e-5);
}

TEST(EarthAndRopeTask, ZeroAdditionCase) {
    double r = 6378100.0;
    double gap = calculateEarthRopeGap(r, 0.0);
    EXPECT_NEAR(0.0, gap, 1e-5);
}

TEST(EarthAndRopeTask, LargeAdditionCase) {
    double r = 6378100.0;
    double gap = calculateEarthRopeGap(r, 100.0);
    EXPECT_NEAR(100.0 / (2.0 * LOCAL_PI), gap, 1e-5);
}

// Group 7: Tasks - Pool
TEST(PoolTask, DefaultCase) {
    // R = 3, width = 1, concrete = 1000, fence = 2000
    // Concrete = pi * (4^2 - 3^2) * 1000 = 7000 * pi
    // Fence = 2 * pi * 4 * 2000 = 16000 * pi
    // Total = 23000 * pi
    double cost = calculatePoolTotalCost(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(23000.0 * LOCAL_PI, cost, 1e-3);
}

TEST(PoolTask, ZeroPathCase) {
    double cost = calculatePoolTotalCost(3.0, 0.0, 1000.0, 2000.0);
    // Concrete = 0
    // Fence = 2 * pi * 3 * 2000 = 12000 * pi
    EXPECT_NEAR(12000.0 * LOCAL_PI, cost, 1e-3);
}

TEST(PoolTask, FreeMaterialsCase) {
    double cost = calculatePoolTotalCost(3.0, 1.0, 0.0, 0.0);
    EXPECT_DOUBLE_EQ(0.0, cost);
}

TEST(PoolTask, OnlyConcreteCostCase) {
    double cost = calculatePoolTotalCost(5.0, 2.0, 500.0, 0.0);
    // Area = pi * (49 - 25) = 24 * pi
    // Cost = 24 * pi * 500 = 12000 * pi
    EXPECT_NEAR(12000.0 * LOCAL_PI, cost, 1e-3);
}

TEST(PoolTask, OnlyFenceCostCase) {
    double cost = calculatePoolTotalCost(5.0, 2.0, 0.0, 500.0);
    // Fence length = 2 * pi * 7 = 14 * pi
    // Cost = 14 * pi * 500 = 7000 * pi
    EXPECT_NEAR(7000.0 * LOCAL_PI, cost, 1e-3);
}
