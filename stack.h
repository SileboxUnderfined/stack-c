#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int length;
    int* data;
} stack;

stack* init_stack();

int* realloc_data(int* data, int length);

void move_elem_right(stack* stk);

void move_elem_left(stack* stk);

void push(stack* stk, int value);

int pop(stack* stk);

unsigned char is_empty(stack* stk);

int top(stack* stk);

void print_stack(stack* stk);

void free_stack(stack* stk);

#endif