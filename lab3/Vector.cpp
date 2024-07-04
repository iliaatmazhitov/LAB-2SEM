//
// Created by Илья Атмажитов on 30.06.2024.
//

#include "Vector.h"
#include <iostream>

template <class T>
void print(const Vector<T>& vec) {
    for (int i = 0; i < vec.get_size(); i++) {
        std::cout << vec.get(i) << " ";
    }
    std::cout << std::endl;
}

// Explicit instantiations for the types used in UI.cpp
template void print(const Vector<int>& vec);
template void print(const Vector<double>& vec);
template void print(const Vector<Complex>& vec);