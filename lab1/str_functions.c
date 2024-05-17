//
// Created by Илья Атмажитов on 29.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "str_functions.h" // Подключаем заголовочный файл с определением структуры Vector и функциями для работы с ней

#define SIZE 256 // Максимальная длина строки

// Функция для вывода строк из вектора
void print_strings(Vector* vector) {
    printf("(%d): ", vector->size); // Выводим размер вектора
    for (int i = 0; i < vector->size; i++) {
        printf("%s ", (char*)vector->data[i]); // Выводим каждую строку из вектора
    }
    printf("\n");
}

// Функция сравнения строк для сортировки вектора
int compare_str(void* p1, void* p2) {
    char* left = (char*)p1;
    char* right = (char*)p2;

    return strcmp(left, right) < 0; // Используем функцию strcmp для сравнения строк
}

// Функция-предикат для where, проверяющая, содержит ли строка только буквенные символы.
int is_all_alphas(void* p) {
    char* s = (char*)p;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z'))
            return 0;
    }

    return 1;
}

// Функция для map, переводящая строку в верхний регистр
void* to_uppercase(void* p) {
    char* s = (char*)p;
    size_t len = strlen(s);
    char* new_s = (char*)malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        new_s[i] = toupper(s[i]);
    }
    new_s[len] = '\0';
    return (void*)new_s;
}

// Функция для ввода вектора строк с клавиатуры
Vector* input_str_vector() {
    int size;

    printf("Введите размер вектора: ");
    scanf("%d", &size);

    if (size <= 0)
        return NULL;

    Vector* vector = init_vector(SIZE, print_strings, compare_str);

    printf("Введите элементы:\n");

    char s[SIZE];
    for (int i = 0; i < size; i++) {
        printf("%d-й элемент: ", i);
        scanf("%s", s);
        char* str = (char*)malloc(strlen(s) + 1); // Выделяем память для строки
        strcpy(str, s); // Копируем строку в выделенную память
        push_vector(vector, (void*)str); // Добавляем указатель на строку в вектор
    }

    return vector;
}