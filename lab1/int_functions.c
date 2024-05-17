//
// Created by Илья Атмажитов on 29.03.2024.
//


#include "int_functions.h" // Подключаем заголовочный файл с определением структуры Vector и функциями для работы с ней

// Функция для вывода целых чисел из вектора
void print_integers(Vector* vector) {
    printf("(%2d): ", vector->size); // Выводим размер вектора
    for (int i = 0; i < vector->size; i++) {
        printf("%4d ", *((int*)vector->data[i])); // Выводим каждое целое число из вектора
    }
    printf("\n");
}

// Функция сравнения целых чисел для сортировки вектора
int compare_int(void* p1, void* p2) {
    int left = *((int*)p1);
    int right = *((int*)p2);

    return left < right; // Сравниваем числа и возвращаем 1 (true), если левое меньше правого
}

// Функция для генерации случайных целых чисел и заполнения ими вектора
void generate_int_data(Vector* vector, int min, int max, int size) {
    // Освобождаем память, занимаемую старыми данными вектора
    for (int i = 0; i < vector->size; i++)
        free(vector->data[i]);
    free(vector->data);

    // Обнуляем вместимость, размер и данные вектора
    vector->capacity = 0;
    vector->size = 0;
    vector->data = NULL;

    // Генерируем случайные целые числа и добавляем их в вектор
    for (int i = 0; i < size; i++) {
        int x = rand() % (max - min + 1) + min; // Генерируем случайное число в заданном диапазоне
        push_vector(vector, (void*)&x); // Добавляем число в вектор
    }
}

// Функция-предикат для where, проверяющая, является ли число четным
int is_even(void* p) {
    int x = *((int*)p);
    return x % 2 == 0; // Возвращает 1 (true), если число четное, иначе 0 (false)
}

// Функция для map, умножающая число на 3
void* multiply_by_3(void* p) {
    int x = *((int*)p);
    x *= 3;
    int* new_x = (int*)malloc(sizeof(int)); // Выделяем память для нового числа
    if (new_x == NULL) {
        // Обработка ошибки выделения памяти
        return NULL;
    }
    *new_x = x; // Сохраняем новое число в выделенной памяти
    return (void*)new_x; // Возвращаем указатель на новое число
}


// Функция для ввода вектора целых чисел с клавиатуры
Vector* input_int_vector() {
    int size;

    printf("Введите размер вектора: ");

    scanf("%d", &size);

    if (size <= 0)
        return NULL; // Если введен неверный размер, возвращаем NULL

    Vector* vector = init_vector(4, print_integers, compare_int); // Создаем вектор, передавая функции для вывода и сравнения целых чисел

    printf("Введите элементы:\n");

    int x;
    for (int i = 0; i < size; i++) {
        printf("%d-й элемент: ", i);
        scanf("%d", &x); // Вводим целое число
        push_vector(vector, (void*)&x); // Добавляем его в вектор
    }

    return vector;
}