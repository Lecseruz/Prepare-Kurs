//
// Created by magomed on 05.04.16.
//
#include <iostream>
#include <cstring>
#include "array.h"

using namespace std;

Array::Array() :
        buffer_(new int[10]),
        reallsize_(0),
        buffsize_(10) { }

Array::~Array() {
    delete[] buffer_;
}

Array::Array(const Array &tmp)
        : reallsize_(0),
          buffsize_(tmp.buffsize_)
{
    buffer_ = new int[tmp.buffsize_];
    for (int i = 0; i < tmp.reallsize_; ++i) {
        buffer_[reallsize_++] = tmp.buffer_[i];
    }
}

int Array::get_at(int index) const {
    return buffer_[index];
}

bool Array::is_empty() const {
    return reallsize_ == 0;
}

void Array::grow() {
    int new_buffsize = max(buffsize_ * 2, 1);
    int *new_arr = new int[new_buffsize];
    memcpy(new_arr, buffer_, reallsize_ * sizeof(char));
    delete[] buffer_;
    buffer_ = new_arr;
    buffsize_ = new_buffsize;
}

void Array::push_back(int element) {
    if (reallsize_ == buffsize_) { grow(); }
        buffer_[reallsize_++] = element;
}

void Array::print() const {
    for (int i = 0; i < reallsize_; ++i) {
        cout << buffer_[i] << " ";
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






