#include <iostream>
#include "Cylinder.h"
#include "ball.h"
#include <fstream>
#include <cstdlib>
#include "shape.h"

using namespace std;

int main(int argc, char *argv[]) {
    int count;

    ifstream file(argv[1]);
    if (!file.is_open()) {
        return -1;
    }
    file >> count;
    AbstractShape **arr_shape = new AbstractShape *[count];

    for (int k = 0; k < count; ++k) {
        int value = rand() % 2;

        switch (value) {
            case 0: {
                arr_shape[k] = new Cylinder;
                arr_shape[k]->info();
                break;
            }
            case 1: {
                arr_shape[k] = new Ball;
                arr_shape[k]->info();
                break;
            }
            default:
                break;
        }
    }

    for (int j = 0; j < 3; ++j) {
        delete arr_shape[j];
    }

    delete[] arr_shape;
    return 0;
}