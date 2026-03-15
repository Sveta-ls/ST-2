// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_
#include "circle.h"

double calcGap(double earthRadius, double addedLength);

double calcPoolBorderCost(double poolRadius,
    double pathWidth,
    double concreteCostPerSqMeter,
    double borderCostPerMeter);

#endif // INCLUDE_TASKS_H_
