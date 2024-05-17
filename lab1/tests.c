//
// Created by Илья Атмажитов on 29.03.2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"
#include "int_functions.h"
#include "str_functions.h"

void test_init_vector() {
    Vector* vector = init_vector(sizeof(int), print_integers, compare_int);
    if (vector == NULL) {
        printf("ERROR: init_vector failed\n");
        return;
    }
    free_vector(vector);
    printf("test_init_vector passed\n");
}

void test_push_vector() {
    Vector* vector = init_vector(sizeof(int), print_integers, compare_int);
    int x = 42;
    push_vector(vector, &x);
    if (vector->size != 1 || *((int*)vector->data[0]) != 42) {
        printf("ERROR: push_vector failed\n");
    }
    free_vector(vector);
    printf("test_push_vector passed\n");
}

void test_sort_vector() {
    Vector* vector = init_vector(sizeof(int), print_integers, compare_int);
    int arr[] = {5, 2, 8, 1, 3};
    for (int i = 0; i < 5; i++) {
        push_vector(vector, &arr[i]);
    }
    sort_vector(vector);
    int expected[] = {1, 2, 3, 5, 8};
    for (int i = 0; i < 5; i++) {
        if (*((int*)vector->data[i]) != expected[i]) {
            printf("ERROR: sort_vector failed\n");
            break;
        }
    }
    free_vector(vector);
    printf("test_sort_vector passed\n");
}

void test_concatenation() {
    Vector* vector1 = init_vector(sizeof(int), print_integers, compare_int);
    Vector* vector2 = init_vector(sizeof(int), print_integers, compare_int);
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    for (int i = 0; i < 3; i++) {
        push_vector(vector1, &arr1[i]);
        push_vector(vector2, &arr2[i]);
    }
    Vector* result = concatenation(vector1, vector2);
    int expected[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        if (*((int*)result->data[i]) != expected[i]) {
            printf("ERROR: concatenation failed\n");
            break;
        }
    }
    free_vector(vector1);
    free_vector(vector2);
    free_vector(result);
    printf("test_concatenation passed\n");
}

void test_where() {
    Vector* vector = init_vector(sizeof(int), print_integers, compare_int);
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        push_vector(vector, &arr[i]);
    }
    Vector* result = where(vector, is_even);
    int expected[] = {2, 4, 6};
    if (result->size != 3) {
        printf("ERROR: where failed\n");
    } else {
        for (int i = 0; i < 3; i++) {
            if (*((int*)result->data[i]) != expected[i]) {
                printf("ERROR: where failed\n");
                break;
            }
        }
    }
    free_vector(vector);
    free_vector(result);
    printf("test_where passed\n");
}

void test_map() {
    Vector* vector = init_vector(sizeof(int), print_integers, compare_int);
    int arr[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        push_vector(vector, &arr[i]);
    }
    Vector* result = map(vector, multiply_by_3);
    int expected[] = {3, 6, 9};
    for (int i = 0; i < 3; i++) {
        if (*((int*)result->data[i]) != expected[i]) {
            printf("ERROR: map failed\n");
            break;
        }
    }
    free_vector(vector);
    free_vector(result);
    printf("test_map passed\n");
}

void test_str_functions() {
    Vector* vector = init_vector(256, print_strings, compare_str);
    char* str1 = "hello";
    char* str2 = "world";
    push_vector(vector, str1);
    push_vector(vector, str2);

    Vector* result = where(vector, is_all_alphas);
    if (result->size != 2) {
        printf("ERROR: is_all_alphas failed\n");
    }

    result = map(vector, to_uppercase);
    char* expected1 = "HELLO";
    char* expected2 = "WORLD";
    if (strcmp((char*)result->data[0], expected1) != 0 || strcmp((char*)result->data[1], expected2) != 0) {
        printf("ERROR: to_uppercase failed\n");
    }

    free_vector(vector);
    free_vector(result);
    printf("test_str_functions passed\n");
}

