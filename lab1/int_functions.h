//
// Created by Илья Атмажитов on 29.03.2024.
//

#ifndef LABORATORY1_INT_FUNCTIONS_H
#define LABORATORY1_INT_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "DynamicArray.h"

void print_integers(Vector* vector);

int compare_int(void* p1, void* p2);

void generate_int_data(Vector* vector, int min, int max, int size);

int is_even(void* p);

void* multiply_by_3(void* p);

Vector* input_int_vector();

#endif //LABORATORY1_INT_FUNCTIONS_H
