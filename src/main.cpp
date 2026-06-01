// Copyright 2026 UNN-CS
#include <iostream>
#include "circle.h"
#include "tasks.h"

int main() {
    double gap = calculateEarthRopeGap(6378100.0, 1.0);
    std::cout << "Earth-rope gap: " << gap << " m\n";

    double total_cost = calculatePoolTotalCost(3.0, 1.0, 1000.0, 2000.0);
    std::cout << "Pool total cost: " << total_cost << " rub\n";

    return 0;
}
