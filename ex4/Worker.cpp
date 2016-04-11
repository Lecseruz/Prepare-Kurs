//
// Created by magomed on 04.04.16.
//

#include "Worker.h"
#include "array.h"
#include <iostream>

using namespace std;

Worker::Worker() { }

Worker::~Worker() { }

Worker::Worker(const Worker &tmp):
        surname_(tmp.surname_),
        initials_(tmp.initials_),
        work_(tmp.work_),
        year_(tmp.year_),
        salary_(tmp.salary_)
{}

void Worker::set_surname(const Array &surname) {
    surname_ = surname;
}

void Worker::set_initials(const Array &initials) {
    initials_ = initials;
}

void Worker::set_work(const Array &word) {
    work_ = word;
}

void Worker::set_year(unsigned int value) {
    year_ = value;
}

void Worker::set_salary(unsigned int value) {
    salary_ = value;
}

Array Worker::get_surname() const {
    return surname_;
}

Array Worker::get_initials() const {
    return initials_;
}

Array Worker::get_work() const {
    return work_;
}

int Worker::get_year() const {
    return year_;
}

int Worker::get_salary() const {
    return salary_;
}

void Worker::show() const {
    surname_.print();
    cout << " ";
    initials_.print();
    cout << " ";
    work_.print();
    cout << " ";
    cout << year_ << " ";
    cout << salary_ << "\n";
}
