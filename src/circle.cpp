// Copyright 2026 UNN-CS
#include "circle.h"
#include <cmath>

const double MY_PI = std::acos(-1.0);

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::updateFromRadius() {
    this->ference = 2.0 * MY_PI * this->radius;
    this->area = MY_PI * this->radius * this->radius;
}

void Circle::updateFromFerence() {
    this->radius = this->ference / (2.0 * MY_PI);
    this->area = MY_PI * this->radius * this->radius;
}

void Circle::updateFromArea() {
    this->radius = std::sqrt(this->area / MY_PI);
    this->ference = 2.0 * MY_PI * this->radius;
}

void Circle::setRadius(double r) {
    this->radius = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    this->ference = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    this->area = a;
    updateFromArea();
}

double Circle::getRadius() const {
    return this->radius;
}

double Circle::getFerence() const {
    return this->ference;
}

double Circle::getArea() const {
    return this->area;
}
