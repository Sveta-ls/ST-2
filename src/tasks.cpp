// Copyright 2026 Svetlana Zyazeva
#include "tasks.h"
#include <cmath>
#include <cstdint>
const double PI = 3.14159265358979;

double calcGap(double earthRadius, double addedLength) {
    double newRadius = earthRadius + (addedLength / (2 * PI));
    return newRadius - earthRadius;
}
double calcPoolBorderCost(double poolRadius, double pathWidth,
    double concreteCostPerSqMeter, double borderCostPerMeter) {
    Circle pool(poolRadius);
    double poolArea = pool.getArea();

    Circle outer(poolRadius + pathWidth);
    double outerArea = outer.getArea();
    double pathArea = outerArea - poolArea;

    double concreteCost = pathArea * concreteCostPerSqMeter;
    double borderCost = outer.getFerence() * borderCostPerMeter;

    return concreteCost + borderCost;
}
