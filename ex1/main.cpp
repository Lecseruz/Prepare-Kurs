#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define max(a, b)  a>b? a: b


int *create_array(char *text, char *word, int count, int count_end) {
    int *array_entry = (int *) malloc(count_end * sizeof(int));
    for (int i = 0; i < count_end; ++i) {
        array_entry[i] = 0;
    }
    int i = 0;
    int k = 0;

    while (strstr(&text[i], word) != NULL) {
        int value = (int) (strstr(&text[i], word) - text);
        for (int j = value; j >= 0; --j) {
            if (text[j] == '?' || text[j] == '.' || text[j] == '!') { k++; }
        }
        array_entry[k]++;
        k = 0;
        i = value + 1;
    }

    return array_entry;
}

char *grow(char *text, int &count) {
    count = max(1, count * 2);
    text = (char *) realloc(text, count * sizeof(char));
    return text;
}

char *read_file_to_buffer(char const *name) {
    char *text = (char *) malloc(sizeof(char));
    int buff_size = 0;
    int i = 0;

    FILE *file = fopen(name, "rt");
    if (!file) {
        printf("error");
        return NULL;
    }

    while (!feof(file)) {
        if (i == buff_size) {
            text = grow(text, buff_size);
        }
        text[i++] = (char) fgetc(file);
    }
    text[i - 1] = '\0';

    return text;
}

int long_text(char *text) {
    int i = 0;

    while (text[i++] != '\0') {
    }
    return i;
}

int count_sentense(char *text) {
    int i = 0;
    int count = 0;
    while (text[i++] != '\0') {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?') { count++; }
    }
    return count;
}

void sort(int *array, int count) {
    int i = 0, j = 0;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {

                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("usage: a.out word filename\n");
        return 0;
    }
    char *word = argv[1];
    char *text = read_file_to_buffer(argv[2]);
    int count = long_text(text);
    int count_end = count_sentense(text);
    int *array = create_array(text, word, count, count_end);

    sort(array, count_end);
    printf("%d\n", array[count_end / 2]);
    return 0;
}