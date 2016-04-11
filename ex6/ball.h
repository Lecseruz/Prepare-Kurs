//
// Created by magomed on 09.04.16.
//
#include "shape.h"

#ifndef EX6_BALL_H
#define EX6_BALL_H


class Ball: public AbstractShape {
public:
    Ball();

    Ball(int radius);

    ~Ball();

    void info();

    int volum();

    int area();

    int get_radius();

    void set_radius(int value);

private:
    int radius_;
};


#endif //EX6_BALL_H
