// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthRopeGap(double earthRadius, double ropeAddition) {
    Circle earth(earthRadius);
    double oldFerence = earth.getFerence();
    earth.setFerence(oldFerence + ropeAddition);
    return earth.getRadius() - earthRadius;
}

double poolConcreteCost(double poolRadius, double pathWidth,
                        double concretePricePerSqM) {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);
    double pathArea = outer.getArea() - pool.getArea();
    return pathArea * concretePricePerSqM;
}

double poolFenceCost(double poolRadius, double pathWidth,
                     double fencePricePerLinM) {
    Circle outer(poolRadius + pathWidth);
    return outer.getFerence() * fencePricePerLinM;
}
