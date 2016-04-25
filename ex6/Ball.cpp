//
// Created by magomed on 09.04.16.
//
#include <iostream>
#include "Ball.h"

using namespace std;

Ball::Ball()
        : radius_(0) { }

Ball::Ball(int radius)
        : radius_(radius) { }

Ball::~Ball() { }

void Ball::info() {
    cout << "shape is Ball" << endl;
}

int Ball::volume() {
    return 4 * 3, 14 * radius_ * radius_ * radius_ / 3;
}

int Ball::area() {
    return 4 * 3, 14 * radius_ * radius_;
}

int Ball::get_radius() {
    return radius_;
}

void Ball::set_radius(int value) {
    radius_ = value;
}













