#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;

Set intersection(const Set &tmp1, const Set &tmp2) {
    Set tmp;
    int k = 0;

    for (int i = 0; i < tmp1.get_reallsize(); ++i) {
        for (int j = 0; j < tmp2.get_reallsize(); ++j) {
            if (tmp1.get_at(i) == tmp2.get_at(j)) {
                k++;
            }
        }
        if (k > 0) {
            tmp.push_back(tmp1.get_at(i));
        }
        k = 0;
    }
    return tmp;
}

Set substraction(const Set &tmp1, const Set &tmp2) {
    Set tmp;
    int k = 0;

    for (int i = 0; i < tmp1.get_reallsize(); ++i) {
        for (int j = 0; j < tmp2.get_reallsize(); ++j) {
            if (tmp1.get_at(i) == tmp2.get_at(j)) {
                k++;
            }
        }
        if (k == 0) {
            tmp.push_back(tmp1.get_at(i));
        }
        k = 0;
    }
    return tmp;
}

Set union_arr(const Set &tmp1, const Set &tmp2) {
    Set tmp;
    int reallsize = tmp1.get_reallsize();

    for (int i = 0; i < reallsize; ++i) {
        tmp.push_back(tmp1.get_at(i));
    }
    reallsize = tmp2.get_reallsize();
    for (int j = 0; j < reallsize; ++j) {
        tmp.push_back(tmp2.get_at(j));
    }
    return tmp;
}

Set *read_array_of_file(ifstream &file, int count_arr) {
    int count;
    Set *set = new Set[count_arr];
    int value;

    for (int i = 0; i < count_arr; ++i) {
        file >> count;
        for (int j = 0; j < count; ++j) {
            file >> value;
            set[i].push_back(value);
        }
    }
    return set;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Error: ./a.out text.txt";
        return -1;
    }
    int count_arr;
    ifstream file(argv[1]);

    file >> count_arr;
    if (!file.is_open()) {
        cout << "Error: file not open";
        return -1;
    }

    Set *array = read_array_of_file(file, count_arr);
    Set tmp = substraction(union_arr(array[1], array[2]), intersection(array[1], array[2]));

    tmp.print();

    return 0;
}