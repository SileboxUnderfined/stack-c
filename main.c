#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"

#define rand_max 10000
#define length_max 15

void push_value_in_stack(stack* stk);

void pop_value_from_stack(stack* stk);

void get_top_of_stack(stack* stk);

void check_if_stack_is_empty(stack* stk);

void fill_stack_rand(stack* stk);

void erase_stack(stack* stk);

int main() {
    srand(time(NULL));
    unsigned char work = 0;
    stack* stk = init_stack();

    while (work == 0) {
        print_stack(stk);
        printf("1 - fill stack with random integers and random length\n");
        printf("2 - push value in stack\n");
        printf("3 - pop value from stack\n");
        printf("4 - get top of stack\n");
        printf("5 - check if stack is empty\n");
        printf("6 - erase stack\n");
        printf("0 - quit\n");
        printf(">> ");
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:
                fill_stack_rand(stk);
                break;
            case 2:
                push_value_in_stack(stk);
                break;
            case 3:
                pop_value_from_stack(stk);
                break;
            case 4:
                get_top_of_stack(stk);
                break;
            case 5:
                check_if_stack_is_empty(stk);
                break;
            case 6:
                erase_stack(stk);
                break;
            case 0:
                work = 1;
                break;
            default:
                printf("Unkown command!\n");
                break;
        }
    }

    free_stack(stk);
    return 0;
}

void push_value_in_stack(stack* stk) {
    int value;
    printf("enter value: ");
    scanf("%d", &value);

    push(stk, value);
}

void pop_value_from_stack(stack* stk) {
    int value = pop(stk);
    printf("Value: %d\n", value);
}

void get_top_of_stack(stack* stk) {
    printf("Top of stack: %d\n", top(stk));
}

void check_if_stack_is_empty(stack* stk) {
    unsigned char r = is_empty(stk);

    r == 1 ? printf("stack is empty\n") : printf("stack is not empty\n");
}

void fill_stack_rand(stack* stk) {
    int length = rand() % length_max + 1;
    for (int i = 0; i < length; i++) {
        int value = rand() % rand_max + 1;
        push(stk, value);
    }
}

void erase_stack(stack* stk) {
    int length = stk->length;
    for (int i = 0; i < length; i++) pop(stk);
}