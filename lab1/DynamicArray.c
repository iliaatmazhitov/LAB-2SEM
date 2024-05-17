//
// Created by Илья Атмажитов on 21.03.2024.
//


#include "DynamicArray.h"

// Функция инициализации вектора
// Принимает размер типа данных, функции для вывода и сравнения элементов
// Возвращает указатель на созданный вектор
Vector* init_vector(int type_size, void (*print)(struct Vector*), int (*comparator)(void*, void*)) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));

    vector->capacity = 0; // Начальная вместимость вектора
    vector->size = 0; // Начальный размер вектора
    vector->type_size = type_size; // Размер типа данных, хранимых в векторе
    vector->data = NULL; // Изначально данные отсутствуют
    vector->print = print; // Функция для вывода элементов вектора
    vector->comparator = comparator; // Функция для сравнения элементов вектора

    return vector;
}

// Функция добавления элемента в вектор
// Принимает указатель на вектор и указатель на добавляемый элемент
void push_vector(Vector* vector, void* ptr_item) {
    // Если вектор пуст, выделяем память для одного элемента
    if (vector->capacity == 0) {
        vector->capacity = 1;
        vector->data = (void**)malloc(sizeof(void*) * vector->capacity);
    }

    // Если вектор заполнен, удваиваем его вместимость
    if (vector->capacity == vector->size) {
        vector->capacity *= 2;

        void** old_data = vector->data;
        vector->data = (void**)malloc(sizeof(void*) * vector->capacity);

        // Копируем старые данные в новый массив
        for (int i = 0; i < vector->size; i++) {
            vector->data[i] = malloc(vector->type_size * sizeof(char));
            char* ptr_data = (char*)vector->data[i];
            char* ptr_old_data = (char*)old_data[i];

            for (int j = 0; j < vector->type_size; j++) {
                ptr_data[j] = ptr_old_data[j];
            }
        }

        // Освобождаем память старого массива
        for (int i = 0; i < vector->size; i++)
            free(old_data[i]);
        free(old_data);
    }

    // Выделяем память для нового элемента и копируем его в вектор
    vector->data[vector->size] = malloc(vector->type_size * sizeof(char));
    char* ptr_data = (char*)vector->data[vector->size];
    char* ptr_item_byte = (char*)ptr_item;

    for (int j = 0; j < vector->type_size; j++) {
        ptr_data[j] = ptr_item_byte[j];
    }

    vector->size++;
}

// Функция вывода элементов вектора
// Принимает указатель на вектор
void print_vector(Vector* vector) {
    vector->print(vector); // Вызов функции вывода, переданной при инициализации вектора
}

// Функция освобождения памяти, занимаемой вектором
// Принимает указатель на вектор
void free_vector(Vector* vector) {
    // Освобождаем память, выделенную для элементов вектора
    for (int i = 0; i < vector->size; i++)
        free(vector->data[i]);

    // Освобождаем память, выделенную для массива указателей
    free(vector->data);
}

// Функция сортировки элементов вектора
// Принимает указатель на вектор
void sort_vector(Vector* vector) {
    // Сортировка методом выбора минимального элемента
    for (int i = 0; i < vector->size; i++) {
        int min_i = i;
        for (int j = i + 1; j < vector->size; j++) {
            if (vector->comparator(vector->data[j], vector->data[min_i])) {
                min_i = j;
            }
        }

        // Обмен элементов для сортировки
        char* ptr_i = (char*)vector->data[i];
        char* ptr_min_i = (char*)vector->data[min_i];

        for (int j = 0; j < vector->type_size; j++) {
            char temp = ptr_i[j];
            ptr_i[j] = ptr_min_i[j];
            ptr_min_i[j] = temp;
        }
    }
}

// Функция объединения двух векторов
// Принимает указатели на два вектора
// Возвращает указатель на новый вектор, содержащий элементы объединенных векторов
Vector* concatenation(Vector* left, Vector* right) {
    // Проверяем, что векторы совместимы (одинаковый тип данных, функции вывода и сравнения)
    if (left->type_size != right->type_size ||
        left->print != right->print ||
        left->comparator != right->comparator) {
        return NULL;
    }

    Vector* new_vector = init_vector(left->type_size, left->print, left->comparator);

    // Копируем элементы из левого вектора в новый
    for (int i = 0; i < left->size; i++) {
        push_vector(new_vector, left->data[i]);
    }

    // Копируем элементы из правого вектора в новый
    for (int i = 0; i < right->size; i++) {
        push_vector(new_vector, right->data[i]);
    }

    return new_vector;
}

// Функция фильтрации элементов вектора по заданному условию
// Принимает указатель на вектор и функцию-предикат для проверки условия
// Возвращает указатель на новый вектор, содержащий элементы, удовлетворяющие условию
Vector* where(Vector* vector, int (*is_suitable)(void*)) {
    Vector* new_vector = init_vector(vector->type_size, vector->print, vector->comparator);

    for (int i = 0; i < vector->size; i++) {
        if (is_suitable(vector->data[i]))
            push_vector(new_vector, vector->data[i]);
    }

    return new_vector;
}

// Функция применения функции к элементам вектора
// Принимает указатель на вектор и функцию для обработки элементов
// Возвращает указатель на новый вектор, содержащий обработанные элементы
Vector* map(Vector* vector, void* (*process)(void*)) {
    Vector* new_vector = init_vector(vector->type_size, vector->print, vector->comparator);

    for (int i = 0; i < vector->size; i++) {
        void* new_element = process(vector->data[i]);
        push_vector(new_vector, new_element);
        free(new_element); // Освобождаем память, выделенную для нового элемента
    }

    return new_vector;
}
