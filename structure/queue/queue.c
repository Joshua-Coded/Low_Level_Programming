#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// initialise the queue
void init_queue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// check if the queue is full
int is_queue_full(Queue *q)
{
    return q->size == MAX_SIZE;
}

// check is the queue empty

int is_queue_empty(Queue *q)
{
    return q->size == 0;
}

// enqueue element
int enqueue(Queue *q, int value)
{
    if (is_queue_full(q))
        return 0; // queue is full
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->array[q->rear] = value;
    q->size++;
    return 1;
}

// dequeue element

int dequeue(Queue *q)
{
    if (is_queue_empty(q))
        return -1; // queue is empty

    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}