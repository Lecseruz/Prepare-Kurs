//
// Created by magomed on 09.04.16.
//

#ifndef EX6_SHAPE_H
#define EX6_SHAPE_H


class AbstractShape {
public:
    virtual void info() = 0;
    virtual int volum() = 0;
    virtual int area() = 0;
    virtual ~AbstractShape() {}
};

#endif //EX6_SHAPE_H
