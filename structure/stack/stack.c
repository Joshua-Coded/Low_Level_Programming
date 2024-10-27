#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// create the stack structure using typedef

typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

// initialize the stack

void init_stack(Stack *s)
{
    s->top = -1;
}

// check if the stack is full
int is_full(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// check of the stack is empty

int is_empty(Stack *s)
{
    return s->top == -1;
}

// push element to the stack

int push(Stack *s, int value)
{
    if (is_full(s))
        return 0;
    s->array[++(s->top)] = value;
    return 1;
}

// pop element from the stack
int pop(Stack *s)
{
    if (is_empty(s))
        return -1; // stack underflow
    return s->array[(s->top)--];
}

// peek top element from the stack
int peek(Stack *s)
{
    if (is_empty(s))
        return -1; // stack underflow
    return s->array[s->top];
}
