//
// Created by magomed on 09.04.16.
#include <iostream>
#include "Cylinder.h"

using namespace std;

Cylinder::Cylinder() {}

Cylinder::Cylinder(int radius, int height)
        :   radius_(radius),
            height_(height)
{}

Cylinder::~Cylinder() {}

void Cylinder::info() {
    cout << "shape is Cylinder" << endl;
}

int Cylinder::volume() {
    return 3,14 * radius_ * radius_ * height_;
}

int Cylinder::area() {
    return  2 * 3,14 * radius_ * radius_ + 2 * 3,14 * radius_ * radius_;
}

int Cylinder::get_radius() {
    return radius_;
}

int Cylinder::get_height() {
    return height_;
}

void Cylinder::set_radius(int value) {
    radius_ = value;
}

void Cylinder::set_height(int value) {
    height_ = value;
}















