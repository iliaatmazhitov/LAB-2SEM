//
// Created by Илья Атмажитов on 15.03.2024.
//


#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#include "int_functions.h"
#include "str_functions.h"
#include "tests.h"


void displayUI() {
    printf("\n________________________________________________________________________________\n");
    printf("1. Выберите тип данных. \n");
    printf("2. Выберите функцию. \n");
    printf("3. Тесты программы. \n");
    printf("0. Выйти.\n");
    printf("________________________________________________________________________________\n");
}

void yourchoice() {

    int choice, choice1, choice2;

    while (1) {
        displayUI();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("________________________________________________________________________________\n");
                printf("1. Целые числа.\n");
                printf("2. Строки.\n");
                printf("________________________________________________________________________________\n");
                scanf("%d", &choice1);
                Vector* vector = NULL;

                int (*where_f)(void*) = NULL;
                void* (*map_f)(void*) = NULL;

                if (choice1 == 1){
                    vector = input_int_vector();
                    where_f = is_even;
                    map_f = multiply_by_3;
                }

                else if (choice1 == 2) {
                    vector = input_str_vector();
                    where_f = is_all_alphas;
                    map_f = to_uppercase;
                }
                break;

            case 2:
                printf("________________________________________________________________________________\n");
                printf("1. Сортировка. \n");
                printf("2. Map. \n");
                printf("3. Where. \n");
                printf("4. Конкатенация.\n");
                printf("________________________________________________________________________________\n");
                scanf("%d", &choice2);

                if (choice2 == 1){
                    printf("До сортировки:\n");
                    print_vector(vector);

                    sort_vector(vector);

                    printf("После сортировки:\n");
                    print_vector(vector);
                }
                if (choice2 == 2) {
                    printf("До map:\n");
                    print_vector(vector);

                    Vector* new_vector = map(vector, map_f);

                    printf("После map:\n");
                    print_vector(new_vector);

                    free_vector(new_vector); // Освобождаем память, выделенную для new_vector
                }

                if (choice2 == 3) {
                    printf("До where:\n");
                    print_vector(vector);

                    Vector* new_vector = where(vector, where_f);

                    printf("После where:\n");
                    print_vector(new_vector);

                    free_vector(new_vector); // Освобождаем память, выделенную для new_vector
                }

                if (choice2 == 4){
                    printf("Изначальный вектор:\n");
                    print_vector(vector);

                    Vector* other_vector = NULL;

                    if (choice1 == 1) {
                        other_vector = input_int_vector();
                    }
                    else if (choice1 == 2) {
                        other_vector = input_str_vector();
                    }

                    printf("Второй вектор:\n");
                    print_vector(other_vector);


                    Vector* result = concatenation(vector, other_vector);

                    printf("Результат конкатенации:\n");
                    print_vector(result);

                    free(other_vector);
                    free(result);
                }

                free_vector(vector);

                break;


            case 3:
                test_init_vector();
                test_push_vector();
                test_sort_vector();
                test_concatenation();
                test_where();
                test_map();
                test_str_functions();
                break;

            case 0:
                exit(0);
                break;

        }
    }


}
