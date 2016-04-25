//
// Created by magomed on 16.04.16.
//

#include "ArrLine.h"

ArrLine::ArrLine()
        :   real_size(0),
            arr(NULL)
{}

ArrLine::ArrLine(int count)
        :   real_size(count),
            arr(new Array<char>[count])
{}


ArrLine::ArrLine(const ArrLine &obj) {
    real_size = obj.real_size;
    arr = new Array<char>[real_size];
    for (int i = 0; i < real_size; ++i) {
        arr[i] = obj.arr[i];
    }
}


ArrLine::~ArrLine() {
    delete[] arr;
}

void ArrLine::read_file_to_buffer(FILE *file) {
    char symbol;
    fscanf(file, "%d", &real_size);
    arr = new Array<char>[real_size];

    for (int i = 0; i < real_size; ++i) {
        while (((symbol = (char) fgetc(file)) != '\n') && !feof(file)) {
                arr[i].push_back(symbol);
        }
    }
}

int ArrLine::get_real_size() {
    return real_size;
}

void ArrLine::print() const {
    for (int i = 0; i < real_size; ++i) {
        arr[i].print();
        cout << endl;
    }
}

void ArrLine::operator=(const ArrLine &obj) {
    real_size = obj.real_size;
    arr = new Array<char>[real_size];
    for (int i = 0; i < real_size; ++i) {
        arr[i] = obj.arr[i];
    }
}

ArrLine ArrLine::operator+(const ArrLine &obj) {
    ArrLine tmp;
    tmp.real_size = real_size + obj.real_size;
    tmp.arr = new Array<char>[tmp.real_size];

    for (int i = 0; i < real_size; ++i) {
        tmp.arr[i] = arr[i];
    }
    for (int i = 0; i < obj.real_size; ++i) {
        tmp.arr[i + real_size] = obj.arr[i];
    }
    return tmp;
}

Array<char> ArrLine::operator[](int value) {
        return arr[value];
}

ostream &operator<<(ofstream &os, ArrLine &obj) {
    for (int i = 0; i < obj.real_size; ++i) {
        obj.arr[i].print();
        cout << endl;
    }
    return os;
}































