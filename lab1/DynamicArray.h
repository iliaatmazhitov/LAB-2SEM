//
// Created by Илья Атмажитов on 21.03.2024.
//

#ifndef LABORATORY1_DYNAMICARRAY_H
#define LABORATORY1_DYNAMICARRAY_H

#include <stdlib.h>



#define INTEGER 0
#define CHAR 1

// Динамический массив
// Целые числа
// Строки


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Vector {
    int capacity;
    int size;
    int type_size;
    void** data;
    void (*print)(struct Vector*);
    int (*comparator)(void*, void*);
};

typedef struct Vector Vector;

Vector* init_vector(int type_size, void (*print)(struct Vector*), int (*comparator)(void*, void*));

void push_vector(Vector* vector, void* ptr_item);

void print_vector(Vector* vector);

void free_vector(Vector* vector);

void sort_vector(Vector* vector);

Vector* concatenation(Vector* left, Vector* right);

Vector* where(Vector* vector, int (*is_suitable)(void*));

Vector* map(Vector* vector, void* (*process)(void*));


#endif //LABORATORY1_DYNAMICARRAY_H
