//
// Created by Илья Атмажитов on 06.05.2024.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H
#include "DynamicArray.h"
#include "Sequence.h"
#include <stdexcept>


template <class T> class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *items;
    int size;
    int capacity;

public:
    ArraySequence() {
        this->items = new DynamicArray<T>;
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
        size = 0;
        capacity = items->GetSize();
    }

    ArraySequence(T *items, int count) {
        this->items = new DynamicArray<T>(items, count);
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
        size = count;
        capacity = this->items->GetSize();
    }

    ArraySequence(int size) {
        this->items = new DynamicArray<T>(size);
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
        this->size = size;
        capacity = size;
    }

    ArraySequence(const ArraySequence<T> &other) {
        this->items = new DynamicArray<T>(*other.items);
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
        size = other.size;
        capacity = other.capacity;
    }

    Sequence<T> *SetImmutable(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        ArraySequence<T> *copy = GetCopy();
        copy->items->Set(index, value);
        return copy;
    }

    Sequence<T> *AppendImmutable(T item) {
        ArraySequence<T> *copy = GetCopy();
        if (copy->size >= copy->capacity) {
            copy->items->Resize(copy->capacity * 2);
            copy->capacity *= 2;
        }
        copy->items->Set(copy->size, item);
        copy->size++;
        return copy;
    }

    Sequence<T> *PrependImmutable(T item) {
        ArraySequence<T> *copy = GetCopy();
        if (copy->size >= copy->capacity) {
            copy->items->Resize(copy->capacity * 2);
            copy->capacity *= 2;
        }
        copy->items->Set(0, item);
        for (int i = copy->size; i > 0; i--) {
            copy->items->Set(i, copy->items->Get(i - 1));
        }
        copy->size++;
        return copy;
    }

    Sequence<T> *InsertAtImmutable(T item, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Invalid index");
        }
        ArraySequence<T> *copy = GetCopy();
        if (copy->size >= copy->capacity) {
            copy->items->Resize(copy->capacity * 2);
            copy->capacity *= 2;
        }
        for (int i = copy->size; i > index; i--) {
            copy->items->Set(i, copy->items->Get(i - 1));
        }
        copy->items->Set(index, item);
        copy->size++;
        return copy;
    }

    virtual ~ArraySequence() {
        if (this->items != nullptr) {
            delete this->items;
        }
    }

    int GetLength() {
        return size;
    }

    T Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }

    T GetLast() {
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->Get(size - 1);
    }

    T GetFirst() {
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->Get(0);
    }

    Sequence<T> *Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        this->items->Set(index, value);
        return this;
    }

    Sequence<T> *Append(T item) {
        if (size >= capacity) {
            items->Resize(capacity * 2);
            capacity *= 2;
        }
        items->Set(size, item);
        size++;
        return this;
    }

    Sequence<T> *Prepend(T item) {
        if (size >= capacity) {
            items->Resize(capacity * 2);
            capacity *= 2;
        }
        items->Set(0, item);
        for (int i = size; i > 0; i--) {
            items->Set(i, items->Get(i - 1));
        }
        size++;
        return this;
    }

    ArraySequence<T> *GetCopy() {
        return new ArraySequence<T>(*this);
    }

    Sequence<T> *InsertAt(T item, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Invalid index");
        }
        if (size >= capacity) {
            items->Resize(capacity * 2);
            capacity *= 2;
        }
        for (int i = size; i > index; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(index, item);
        size++;
        return this;
    }

    Sequence<T> *GetSubsequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("Invalid index range");
        }
        DynamicArray<T> *subArray = this->items->GetSubsequence(startIndex, endIndex);
        ArraySequence<T> *result = new ArraySequence<T>(subArray->Get_data(), endIndex - startIndex + 1);
        delete subArray;
        return result;
    }

    T *Get_adress() const {
        return items->Get_data();
    }

    void Print() {
        this->items->Print();
    }

    Sequence<T> *Concat(Sequence<T> *list) {
        ArraySequence<T> *other = dynamic_cast<ArraySequence<T> *>(list);
        if (other == nullptr) {
            throw std::invalid_argument("Invalid sequence type");
        }
        int newSize = size + other->size;
        if (newSize > capacity) {
            while (newSize > capacity) {
                capacity *= 2;
            }
            items->Resize(capacity);
        }
        for (int i = 0; i < other->size; i++) {
            items->Set(size + i, other->items->Get(i));
        }
        size = newSize;
        return this;
    }

    Sequence<T> *ConcatImmutable(Sequence<T> *list) {
        ArraySequence<T> *copy = GetCopy();
        ArraySequence<T> *other = dynamic_cast<ArraySequence<T> *>(list);
        if (other == nullptr) {
            throw std::invalid_argument("Invalid sequence type");
        }
        DynamicArray<T> *newItems = copy->items->Concat(other->items);
        Sequence<T> *result = new ArraySequence<T>(newItems->Get_data(), newItems->GetSize());
        delete newItems;
        return result;
    }
};
#endif // LAB2_ARRAYSEQUENCE_H
