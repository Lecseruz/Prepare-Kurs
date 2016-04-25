#include <iostream>
#include <cstdlib>
#include "Cylinder.h"
#include "Ball.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Error: ./a.out text.txt";
        return -1;
    }
    int count;
    ifstream file(argv[1]);

    file >> count;

    AbstractShape **arr_shape = new AbstractShape *[count];

    srand(time(NULL));
    for (int i = 0; i < count; ++i) {
        int value = rand() % 2;

        switch (value) {
            case 0: {
                arr_shape[i] = new Cylinder(5, 6);
                cout << arr_shape[i]->volume() << endl;
                break;
            }
            case 1: {
                arr_shape[i] = new Ball(5);
                cout << arr_shape[i]->volume() << endl;
                break;
            }
            default:
                break;
        }
    }

    for (int i = 0; i < count; ++i) {
        arr_shape[i]->info();
    }
    for (int i = 0; i < count; ++i) {
        delete arr_shape[i];
    }
    delete[] arr_shape;

    return 0;
}