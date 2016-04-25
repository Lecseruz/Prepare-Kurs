//
// Created by magomed on 09.04.16.
//

#include "Shape.h"

#ifndef EX6_SYLINDER_H
#define EX6_SYLINDER_H


class Cylinder : public AbstractShape {
public:
    Cylinder();

    Cylinder(int radius, int height);

    ~Cylinder();

    void info();

    int volume();

    int area();

    int get_radius();

    int get_height();

    void set_radius(int value);

    void set_height(int value);
private:
    int radius_;
    int height_;
};


#endif //EX6_SYLINDER_H
