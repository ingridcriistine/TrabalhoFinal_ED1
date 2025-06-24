#include <stdio.h>
#include <string.h>
#include <cstdlib>
#ifndef HEADER_H
#define HEADER_H

typedef struct
{
    int size;
    int capacity;
    int *array;

} Stack;

Stack construct()
{
    Stack stack;

    stack.size = 0;
    stack.capacity = 0;
    stack.array = NULL;

    return stack;
}

void Destruct(Stack *stack) {

    free(stack->array);
}

void Push(Stack *stack, int value)
{
    if (stack->array == NULL)
    {
        stack->capacity = 2;
        stack->array = (int*) malloc(stack->capacity * sizeof(int));
        stack->array[stack->size] = value;
        stack->size++;

        return;
    }

    if (stack->capacity == stack->size)
    {
        stack->capacity = stack->capacity * 2;
        realloc(stack->array, stack->capacity * sizeof(int));
    }

    stack->array[stack->size] = value;
    stack->size++;

}

int Pop(Stack *stack)
{
    stack->size--;
    int aux = stack->array[stack->size];

    return aux;
}

int Top(Stack *stack)
{
    return stack->array[stack->size-1];
}

#endif