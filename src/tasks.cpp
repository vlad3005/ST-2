// Copyright 2026 UNN-CS
#include "tasks.h"
#include "circle.h"

double calculateEarthRopeGap(double r_earth, double extra_rope) {
    Circle planet(r_earth);
    double initial_circumference = planet.getFerence();
    
    // Add extra rope
    planet.setFerence(initial_circumference + extra_rope);
    
    // Gap is the new radius minus the old radius
    return planet.getRadius() - r_earth;
}

double calculatePoolTotalCost(double radius_pool, double path_width, double conc_price, double fence_price) {
    Circle inner_pool(radius_pool);
    Circle outer_pool(radius_pool + path_width);
    
    double area_of_path = outer_pool.getArea() - inner_pool.getArea();
    double concrete_cost = area_of_path * conc_price;
    
    double length_of_fence = outer_pool.getFerence();
    double fence_cost = length_of_fence * fence_price;
    
    return concrete_cost + fence_cost;
}
