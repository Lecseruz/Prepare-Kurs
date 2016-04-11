//
// Created by magomed on 06.04.16.
//

#include "set.h"

void Set::push_back(int element) {
    if (reallsize_ == buffsize_) { grow(); }
    for (int i = 0; i < reallsize_; ++i) {
        if (buffer_[i] == element) {
            return;
        }
    }
    buffer_[reallsize_++] = element;
}

Set::Set() {}

Set::~Set() {}










