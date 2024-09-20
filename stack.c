#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* init_stack() {
    stack* result = malloc(sizeof(stack));
    result->length = 0;
    result->data = calloc(result->length, sizeof(int));

    return result;
}

int* realloc_data(int* data, int length) {
    int* new_data = realloc(data, length*sizeof(int));

    return new_data;
}

void move_elem_right(stack* stk) {
    stk->length++;
    stk->data = realloc_data(stk->data, stk->length);

    for (int i = stk->length-1; i > 0; i--) {
        stk->data[i] = stk->data[i-1];
    }
}

void move_elem_left(stack* stk) {
    for (int i = 0; i < stk->length-1; i++) {
        stk->data[i] = stk->data[i+1];
    }

    stk->length--;
    stk->data = realloc_data(stk->data, stk->length);
}

void push(stack* stk, int value) {
    move_elem_right(stk);

    stk->data[0] = value;
}

int pop(stack* stk) {
    int result = stk->data[0];

    move_elem_left(stk);

    return result;
}

unsigned char is_empty(stack* stk) {
    if (stk->length == 0) return 1;
    else return 0;
}

int top(stack* stk) {
    return stk->data[0];
}

void print_stack(stack* stk) {
    printf("Stack length: %d\n", stk->length);

    for (int i = 0; i < stk->length; i++) {
        printf("%d ", stk->data[i]);
    }
    printf("\n");
}

void free_stack(stack* stk) {
    free(stk->data);
    free(stk);
}