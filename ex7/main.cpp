#include "ArrLine.h"

ArrLine merge( ArrLine &obj1, ArrLine &obj2){
    ArrLine obj3(obj1 + obj2);
    Array<char> temp;

    for (int i = obj3.get_real_size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (obj3[j] < obj3[j + 1])
            {
                temp = obj3[j];
                obj3[j] = obj3[j + 1];
                obj3[j + 1] = temp;
            }
        }
    }
    return obj3;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Error: ./a/out text.txt";
        return -1;
    }

    int count;
    FILE *file = fopen("text.txt", "r");

    if (!file) {
        printf("error");
        return -1;
    }
    fscanf(file, "%d", &count);
    ArrLine *arr = new ArrLine[count];
    for (int i = 0; i < count; ++i) {
       arr[i].read_file_to_buffer(file);
    }
    ArrLine tmp = merge(arr[0], arr[1]);
    tmp.print();
    //for (int i = 0; i < count; ++i) {
    //    arr[i].print();
   // }
    fclose(file);
    delete[] arr;

    return 0;
}