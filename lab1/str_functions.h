//
// Created by Илья Атмажитов on 29.03.2024.
//

#ifndef LABORATORY1_STR_FUNCTIONS_H
#define LABORATORY1_STR_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "DynamicArray.h"

void print_strings(Vector* vector);

int compare_str(void* p1, void* p2);

int is_all_alphas(void* p);

void* to_uppercase(void* p);

Vector* input_str_vector();

#endif //LABORATORY1_STR_FUNCTIONS_H
