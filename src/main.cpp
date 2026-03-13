// Copyright 2022 UNN-CS
#include <iostream>
#include "circle.h"
#include "tasks.h"

int main() {
    double gap = earthRopeGap(6378100.0, 1.0);
    std::cout << "Earth-rope gap: " << gap << " m\n";

    double concrete = poolConcreteCost(3.0, 1.0, 1000.0);
    double fence    = poolFenceCost(3.0, 1.0, 2000.0);
    std::cout << "Pool concrete cost: " << concrete << " rub\n";
    std::cout << "Pool fence cost:    " << fence    << " rub\n";

    return 0;
}

