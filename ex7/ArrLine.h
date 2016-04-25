//
// Created by magomed on 16.04.16.
//

#ifndef ARRAY_LINE_ARR_LINE_H
#define ARRAY_LINE_ARR_LINE_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Array.h"

using namespace std;

#define min(a,b) a < b ? b : a

class ArrLine {
public:
    ArrLine();
    ArrLine(int count);
    ~ArrLine();
    ArrLine(const ArrLine &obj);
    void read_file_to_buffer(FILE *file);
    void print() const;
    int get_real_size();
    ArrLine operator+(const ArrLine &obj);
    void operator=(const ArrLine &obj);
    Array<char> operator[](int value);
    friend ostream &operator<<(ofstream &os, ArrLine &obj);
private:
    Array<char> *arr;
    int real_size;
};



#endif //ARRAY_LINE_ARR_LINE_H
