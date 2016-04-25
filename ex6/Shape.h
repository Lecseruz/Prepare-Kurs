//
// Created by magomed on 09.04.16.
//

#ifndef EX6_SHAPE_H
#define EX6_SHAPE_H
#include <iostream>
#include <fstream>


class AbstractShape {
public:
    virtual ~AbstractShape() {}
    virtual void info() = 0;
    virtual int volume() = 0;
    virtual int area() = 0;
};

#endif //EX6_SHAPE_H
