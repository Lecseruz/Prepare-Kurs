//
// Created by magomed on 04.04.16.
//

#ifndef EX4_WORKER_H
#define EX4_WORKER_H

#include <iostream>
#include "array.h"
using namespace std;

#define max(a, b) a < b ? b : a

class Worker {
public:
    Worker();

    ~Worker();

    Worker(const Worker &tmp);

    void set_surname(const Array &surname);

    void set_initials(const Array &initials);

    void set_work(const Array &work);

    void set_year(unsigned int value);

    void set_salary(unsigned int value);

    Array get_surname() const;

    Array get_initials() const;

    Array get_work() const;

    int get_year() const;

    int get_salary() const;

    void show() const;

private:
    Array surname_;
    Array initials_;
    Array work_;
    unsigned int year_;
    unsigned int salary_;
};

#endif //EX4_WORKER_H
