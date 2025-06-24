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

} Queue;

Queue construct_()
{
    Queue queue;
    queue.size = 0;
    queue.capacity = 0;
    queue.array = NULL;

    return queue;
}

void Destruct_(Queue *queue) {

    free(queue->array);
}

void Enqueue(Queue *queue, int value)
{
     if(queue->array == NULL) {

        queue->capacity = 2;
        queue->array = (int*) malloc(queue->capacity * sizeof(int));

     }

     if(queue->size == queue->capacity) {

        queue->capacity *= 2;
        realloc(queue->array, queue->capacity * sizeof(int));

     }

    queue->array[queue->size] = value;
    queue->size++;

}

int Dequeue(Queue *queue)
{
    int aux = queue->array[0];

    for(int i = 0; i < queue->size; i++) {
        queue->array[i] = queue->array[i+1];
    }

    queue->size--;

    return aux;
}

#endif