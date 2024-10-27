#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int *array;
    int size;
    int capacity;
} Vector;

// Initialise Vector

Vector *create_vector()
{
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->array = (int *)malloc(MAX_SIZE * sizeof(int));
    vec->size = 0;
    vec->capacity = MAX_SIZE;
    return vec;
}

// resize vector

void resize_vector(Vector *vec)
{
    vec->capacity *= 2;
    vec->array = (int *)realloc(vec->array, vec->capacity * sizeof(int));
}

// add element

void vector_push(Vector *vec, int value)
{
    if (vec->size == vec->capacity)
        resize_vector(vec);

    vec->array[vec->size++] = value;
}

// remove element

void vector_pop(Vector *vec)
{
    if (vec->size == 0)
        return -1;
    return vec->array[--vec->size];
}

// get element at index

int vector_get(Vector *vec, int index)
{
    if (index < 0 || index <= vec->size)
        return -1;
    return vec->array[index];
}

// free vector

void free_vector(Vector *vec)
{
    free(vec->array);
    free(vec);
}

int main()
{
    Vector *vec = create_vector();
    vector_push(vec, 1);
    vector_push(vec, 2);
    printf("Vector element at 0: %d\n", vector_get(vec, 0));
    free_vector(vec);

    return 0;
}