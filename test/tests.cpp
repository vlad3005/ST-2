// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static const double PI = 3.14159265358979323846;

// ──────────────────── Circle: constructor ────────────────────

TEST(CircleConstructor, RadiusSet) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
}

TEST(CircleConstructor, FerenceCalculated) {
    Circle c(5.0);
    EXPECT_NEAR(2.0 * PI * 5.0, c.getFerence(), 1e-9);
}

TEST(CircleConstructor, AreaCalculated) {
    Circle c(5.0);
    EXPECT_NEAR(PI * 25.0, c.getArea(), 1e-9);
}

TEST(CircleConstructor, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

// ──────────────────── Circle: setRadius ──────────────────────

TEST(CircleSetRadius, UpdatesRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(10.0, c.getRadius());
}

TEST(CircleSetRadius, RecalculatesFerence) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(2.0 * PI * 3.0, c.getFerence(), 1e-9);
}

TEST(CircleSetRadius, RecalculatesArea) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(PI * 9.0, c.getArea(), 1e-9);
}

// ──────────────────── Circle: setFerence ─────────────────────

TEST(CircleSetFerence, RecalculatesRadius) {
    Circle c(1.0);
    double f = 2.0 * PI * 7.0;
    c.setFerence(f);
    EXPECT_NEAR(7.0, c.getRadius(), 1e-9);
}

TEST(CircleSetFerence, UpdatesFerence) {
    Circle c(1.0);
    double f = 2.0 * PI * 4.0;
    c.setFerence(f);
    EXPECT_NEAR(f, c.getFerence(), 1e-9);
}

TEST(CircleSetFerence, RecalculatesArea) {
    Circle c(1.0);
    double f = 2.0 * PI * 4.0;
    c.setFerence(f);
    EXPECT_NEAR(PI * 16.0, c.getArea(), 1e-9);
}

// ──────────────────── Circle: setArea ────────────────────────

TEST(CircleSetArea, RecalculatesRadius) {
    Circle c(1.0);
    c.setArea(PI * 36.0);
    EXPECT_NEAR(6.0, c.getRadius(), 1e-9);
}

TEST(CircleSetArea, UpdatesArea) {
    Circle c(1.0);
    double a = PI * 9.0;
    c.setArea(a);
    EXPECT_NEAR(a, c.getArea(), 1e-9);
}

TEST(CircleSetArea, RecalculatesFerence) {
    Circle c(1.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(2.0 * PI * 3.0, c.getFerence(), 1e-9);
}

// ──────────────────── Circle: round-trip consistency ─────────

TEST(CircleConsistency, SetRadiusThenArea) {
    Circle c(2.0);
    c.setRadius(5.0);
    EXPECT_NEAR(PI * 25.0, c.getArea(), 1e-9);
    EXPECT_NEAR(2.0 * PI * 5.0, c.getFerence(), 1e-9);
}

TEST(CircleConsistency, SetFerenceThenRadius) {
    Circle c(1.0);
    c.setFerence(2.0 * PI * 8.0);
    EXPECT_NEAR(8.0, c.getRadius(), 1e-9);
    EXPECT_NEAR(PI * 64.0, c.getArea(), 1e-9);
}

TEST(CircleConsistency, SetAreaThenFerence) {
    Circle c(1.0);
    c.setArea(PI * 100.0);
    EXPECT_NEAR(10.0, c.getRadius(), 1e-9);
    EXPECT_NEAR(2.0 * PI * 10.0, c.getFerence(), 1e-9);
}

// ──────────────────── Task: Earth & Rope ─────────────────────

TEST(EarthRope, GapWith1Meter) {
    double gap = earthRopeGap(6378100.0, 1.0);
    EXPECT_NEAR(1.0 / (2.0 * PI), gap, 1e-6);
}

TEST(EarthRope, GapIsIndependentOfRadius) {
    double gap1 = earthRopeGap(6378100.0, 1.0);
    double gap2 = earthRopeGap(1.0,       1.0);
    EXPECT_NEAR(gap1, gap2, 1e-6);
}

TEST(EarthRope, GapWith2Meters) {
    double gap = earthRopeGap(6378100.0, 2.0);
    EXPECT_NEAR(2.0 / (2.0 * PI), gap, 1e-6);
}

// ──────────────────── Task: Pool ─────────────────────────────

TEST(Pool, ConcreteCost) {
    double cost = poolConcreteCost(3.0, 1.0, 1000.0);
    EXPECT_NEAR(7.0 * PI * 1000.0, cost, 1e-4);
}

TEST(Pool, FenceCost) {
    double cost = poolFenceCost(3.0, 1.0, 2000.0);
    EXPECT_NEAR(8.0 * PI * 2000.0, cost, 1e-4);
}

TEST(Pool, ConcreteCostZeroPath) {
    double cost = poolConcreteCost(3.0, 0.0, 1000.0);
    EXPECT_NEAR(0.0, cost, 1e-9);
}

TEST(Pool, FenceCostEqualsOuterCircumferencePriced) {
    double outerR = 5.0 + 2.0;  
    double expected = 2.0 * PI * outerR * 500.0;
    double cost = poolFenceCost(5.0, 2.0, 500.0);
    EXPECT_NEAR(expected, cost, 1e-9);
}

