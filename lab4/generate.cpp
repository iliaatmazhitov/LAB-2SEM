//
// Created by Илья Атмажитов on 24.05.2024.
//


#include "generate.h"

int generate_int() {
    return rand() % 1001 - 500;
}

string generate_string() {
    int size = rand() % 10 + 1;
    string random(size, ' ');

    for (int i = 0; i < size; i++) {
        random[i] = rand() % 26 + 'A';
    }

    return random;
}