//
//  Vector.h
//  laboratory3
//
//  Created by Илья Атмажитов on 19.06.2024.
//

#ifndef Vector_h
#define Vector_h

#include "exception"
#include <cmath>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Complex.h"
#include <type_traits>

template <class T>
class Vector {
private:
    Sequence<T>* vec;

public:
    Vector(int type, int size = 0) {
        if (type == 1) {
            vec = new ArraySequence<T>(size);
        } else if (type == 2) {
            vec = new ListSequence<T>(size);
        } else {
            throw invalid_argument("Invalid type");
        }
    }

    ~Vector() {
        delete vec;
    }

    Vector(const Vector & other) : vec(nullptr) {
        if (dynamic_cast<ArraySequence<T>*>(other.vec)) {
            vec = new ArraySequence<T>(*dynamic_cast<ArraySequence<T>*>(other.vec));
        } else if (dynamic_cast<ListSequence<T>*>(other.vec)) {
            vec = new ListSequence<T>(*dynamic_cast<ListSequence<T>*>(other.vec));
        }
    }

    void set(const int & index, const T & item) {
        vec->Set(index, item);
    }

    T get(const int & index) const {
        return vec->get(index);
    }

    T & Get(int index) {
        return vec->Get(index);
    }

    int get_size() const {
        return vec->GetLength();
    }

    Vector<T> operator+(const Vector<T>& other) const {
        if (this->get_size() != other.get_size()) {
            throw invalid_argument("Vectors must have the same size");
        }

        Vector<T> result(dynamic_cast<ArraySequence<T>*>(vec) ? 1 : 2, this->get_size());
        for (int i = 0; i < this->get_size(); i++) {
            result[i] = (*this)[i] + other[i];
        }

        return result;
    }

    Vector<T> operator*(T scalar) const {
        Vector<T> result(dynamic_cast<ArraySequence<T>*>(vec) ? 1 : 2, this->get_size());
        for (int i = 0; i < this->get_size(); i++) {
            result[i] = (*this)[i] * scalar;
        }
        return result;
    }

    T dot(const Vector<T>& other) const {
        if (this->get_size() != other.get_size()) {
            throw invalid_argument("Vectors must have the same size");
        }

        T result = T(0);
        for (int i = 0; i < this->get_size(); i++) {
            result += (*this)[i] * other[i];
        }
        return result;
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete vec;
            if (dynamic_cast<ArraySequence<T>*>(other.vec)) {
                vec = new ArraySequence<T>(*dynamic_cast<ArraySequence<T>*>(other.vec));
            } else if (dynamic_cast<ListSequence<T>*>(other.vec)) {
                vec = new ListSequence<T>(*dynamic_cast<ListSequence<T>*>(other.vec));
            }
        }
        return *this;
    }

    T operator[](int index) const {
        return get(index);
    }

    T & operator[](int index) {
        return Get(index);
    }
};

template <class T>
void print(const Vector<T>& vec);


#endif /* Vector_h */
