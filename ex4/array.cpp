//
// Created by magomed on 03.04.16.
//
#include <iostream>
#include <cstring>
#include <cassert>
#include "array.h"

using namespace std;

#define max(a, b) a < b ? b : a

#include "array.h"


Array::Array() :
        buffer_(new char[10]),
        reallsize_(0),
        buffsize_(10) { }

Array::~Array() {
    delete[] buffer_;
}

Array::Array(const Array &tmp) :
        reallsize_(0),
        buffsize_(tmp.buffsize_) {
    buffer_ = new char[tmp.buffsize_];
    for (int i = 0; i < tmp.reallsize_; ++i) {
        buffer_[reallsize_++] = tmp.buffer_[i];
    }
}

char Array::get_at(int index) const {
    //assert(index >= 0 && index < reallsize_);

    return buffer_[index];
}

bool Array::is_empty() const {
    return reallsize_ == 0;
}

void Array::grow() {
    int new_buffsize = max(buffsize_ * 2, 1);
    char *new_arr = new char[new_buffsize];
    memcpy(new_arr, buffer_, reallsize_ * sizeof(char));
    delete[] buffer_;
    buffer_ = new_arr;
    buffsize_ = new_buffsize;
}

void Array::push_back(char element) {
    if (reallsize_ == buffsize_) { grow(); }

    buffer_[reallsize_++] = element;
}

void Array::print() const {
    for (int i = 0; i < reallsize_; ++i) {
        cout << buffer_[i];
    }
}

void Array::operator=(const Array &tmp) {
    for (int i = 0; i < tmp.reallsize_; ++i) {
        push_back(tmp.get_at(i));
    }
    reallsize_ = tmp.reallsize_;
    buffsize_ = tmp.buffsize_;
}

int Array::get_reallsize() const {
    return reallsize_;
}

bool Array::operator==(const Array &tmp) const {
    if (reallsize_ != tmp.get_reallsize()) { return false; }
    for (int i = 0; i < reallsize_; ++i) {
        if (buffer_[i] != tmp.buffer_[i]) { return false; }
    }
    return true;
}









