// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double earthRopeGap(double earthRadius, double ropeAddition);

double poolConcreteCost(double poolRadius, double pathWidth,
                        double concretePricePerSqM);

double poolFenceCost(double poolRadius, double pathWidth,
                     double fencePricePerLinM);

#endif  // INCLUDE_TASKS_H_
