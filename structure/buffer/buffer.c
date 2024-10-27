#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int head;
    int tail;
    int full;
} CircularBuffer;

// initialise buffer

void init_circular_buffer(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->full = 0;
}

// check if circular buffer is full

int is_buffer_full(CircularBuffer *cb)
{
    return cb->full;
}

// check if circular buffer is empty

int is_buffer_empty(CircularBuffer *cb)
{
    return (!cb->full && (cb->head == cb->tail));
}

// write into the buffer

int write_buffer(CircularBuffer *cb, int value)
{
    if (is_buffer_full(cb))
        return 0;

    cb->array[cb->head] = value;
    cb->head = (cb->head + 1) % MAX_SIZE;

    if (cb->head == cb->tail)
        cb->full = 1;
    return 1;
}

int read_buffer(CircularBuffer *cb)
{
    if (is_buffer_empty(cb))
        return -1;

    int value = cb->array[cb->tail];
    cb->tail = (cb->tail + 1) % MAX_SIZE;
    cb->full = 0;
    return value;
}
