#pragma once

#include <stdexcept>

template<class T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray() : data(nullptr), size(0) {}

    DynamicArray(T* items, int count) {
        size = count;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = items[i];
        }
    }

    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }
        this->size = size;
        data = new T[size];
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) {
        size = dynamicArray.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = dynamicArray.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }


    T & Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    T GetFirst() const{
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }

        return data[0];
    }

    T GetLast() const{
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }

        return data[size - 1];
    }


    int GetSize() const {
        return size;
    }

    void Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        data[index] = value;
    }

    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("New size cannot be negative");
        }

        if (newSize > size) {
            T* oldData = data;
            data = new T[newSize];

            for (int i = 0; i < size; i++) {
                data[i] = oldData[i];
            }

            delete[] oldData;
        }

        size = newSize;
    }


    DynamicArray& operator=(const DynamicArray& other) {
        if (&other != this) {
            size = other.size;
            delete[] data;
            data = new T[size];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }


};

