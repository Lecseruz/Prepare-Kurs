#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int value;
    Stack *next = NULL;
};

bool is_empty(Stack *head) {
    return head == NULL;
}

void push(Stack *&head, int value) {
    Stack *new_head = (Stack *) malloc(sizeof(Stack *));

    new_head->value = value;
    new_head->next = head;
    head = new_head;
}

int pop(Stack *&head) {
    if (is_empty(head)) {
        printf("Warning: stack is empty\n");

        return -1;
    }
    int a = head->value;
    Stack *p = head;

    head = head->next;
    free(p);

    return a;
}

int calculate(FILE *file) {
    Stack *stack = (Stack *) malloc(sizeof(Stack *));
    int symvol = 0;

    while ((symvol = fgetc(file)) != EOF) {
        if (symvol != '+' && symvol != '-' && symvol != '/' && symvol != '*') {
            push(stack, symvol - 48);
        } else {
            switch (symvol) {
                case '+': {
                    int a = pop(stack), b = pop(stack);
                    int s = b + a;

                    push(stack, s);
                    break;
                }
                case '-': {
                    int a = pop(stack), b = pop(stack);
                    int s = b - a;

                    push(stack, s);
                    break;
                }
                case '/': {
                    int a = pop(stack), b = pop(stack);
                    int s = b / a;

                    push(stack, s);
                    break;
                }
                case '*': {
                    int a = pop(stack), b = pop(stack);
                    int s = b * a;

                    push(stack, s);
                    break;
                }
                default:
                    break;
            }
        }
    }
    int result = pop(stack);

    free(stack);

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: use a.out filename\n");

        return -1;
    }
    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        printf("Error: open file!\n");

        return -1;
    }
    int result = calculate(file);

    printf("%d\n", result);
    fclose(file);

    return 0;
}