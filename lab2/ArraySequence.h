//
// Created by Илья Атмажитов on 06.05.2024.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H
#include "DynamicArray.h"
#include "Sequence.h"
#include <stdexcept>

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;
    int capacity;

    void ensureCapacity() {
        if (GetLength() == capacity) {
            capacity *= 2;
            DynamicArray<T>* newItems = new DynamicArray<T>(capacity);
            for (int i = 0; i < GetLength(); i++) {
                newItems->Set(i, items->Get(i));
            }
            delete items;
            items = newItems;
        }
    }

public:
    ArraySequence() {
        this->items = new DynamicArray<T>;
        capacity = 0;
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
    }

    ArraySequence(T* items, int count) {
        this->items = new DynamicArray<T>(items, count);
        capacity = count * 2;
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
    }

    ArraySequence(int size) {
        this->items = new DynamicArray<T>(size);
        capacity = size * 2;
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
    }

    ArraySequence(const ArraySequence<T>& other) {
        this->items = new DynamicArray<T>(*other.items);
        capacity = other.capacity;
        if (this->items == nullptr) {
            throw std::bad_alloc();
        }
    }

    Sequence<T>* SetImmutable(int index, T value) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        ensureCapacity();
        ArraySequence<T>* copy = GetCopy();
        copy->items->Set(index, value);
        return copy;
    }

    Sequence<T>* AppendImmutable(T item) {
        ensureCapacity();
        ArraySequence<T>* copy = GetCopy();
        copy->items->Resize(copy->GetLength() + 1);
        copy->items->Set(copy->GetLength() - 1, item);
        return copy;
    }

    Sequence<T>* PrependImmutable(T item) {
        ensureCapacity();
        ArraySequence<T>* copy = GetCopy();
        int size = copy->items->GetSize();
        DynamicArray<T>* oldArray = copy->items;
        copy->items = new DynamicArray<T>(size + 1);
        for (int i = 0; i < size; i++) {
            copy->items->Set(i + 1, oldArray->Get(i));
        }
        copy->items->Set(0, item);
        delete oldArray;
        return copy;
    }

    Sequence<T>* InsertAtImmutable(T item, int index) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        ensureCapacity();
        ArraySequence<T>* copy = GetCopy();
        copy->items->Set(index, item);
        return copy;
    }

    virtual ~ArraySequence() {
        if (this->items != nullptr) {
            delete this->items;
        }
    }

    int GetLength() {
        return this->items->GetSize();
    }

    T Get(int index) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }

    T GetLast() {
        if (GetLength() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetLast();
    }

    T GetFirst() {
        if (GetLength() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetFirst();
    }

    Sequence<T>* Set(int index, T value) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        ensureCapacity();
        this->items->Set(index, value);
        return this;
    }

    Sequence<T>* Append(T item) {
        ensureCapacity();
        this->items->Resize(this->items->GetSize() + 1);
        this->items->Set(this->items->GetSize() - 1, item);
        return this;
    }

    Sequence<T>* Prepend(T item) {
        ensureCapacity();
        int size = this->items->GetSize();
        DynamicArray<T>* oldArray = this->items;
        this->items = new DynamicArray<T>(size + 1);
        for (int i = 0; i < size; i++) {
            this->items->Set(i + 1, oldArray->Get(i));
        }
        this->items->Set(0, item);
        delete oldArray;
        return this;
    }

    ArraySequence<T>* GetCopy() {
        return new ArraySequence<T>(*this);
    }

    Sequence<T>* InsertAt(T item, int index) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        ensureCapacity();
        this->items->Set(index, item);
        return this;
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= GetLength() || endIndex < 0 || endIndex >= GetLength() || startIndex > endIndex) {
            throw std::out_of_range("Invalid index range");
        }
        DynamicArray<T>* subArray = this->items->GetSubsequence(startIndex, endIndex);
        ArraySequence<T>* result = new ArraySequence<T>(subArray->Get_data(), subArray->GetSize());
        delete subArray;
        return result;
    }

    T* Get_adress() const {
        return items;
    }

    void Print() {
        this->items->Print();
    }

    Sequence<T>* Concat(Sequence<T>* list) {
        ArraySequence<T>* other = dynamic_cast<ArraySequence<T>*>(list);
        if (other == nullptr) {
            throw std::invalid_argument("Invalid sequence type");
        }
        ensureCapacity();
        DynamicArray<T>* newItems = this->items->Concat(other->items);
        Sequence<T>* result = new ArraySequence<T>(newItems->Get_data(), newItems->GetSize());
        delete newItems;
        return result;
    }

    Sequence<T>* ConcatImmutable(Sequence<T>* list) {
        ArraySequence<T>* copy = GetCopy();
        ArraySequence<T>* other = dynamic_cast<ArraySequence<T>*>(list);
        if (other == nullptr) {
            throw std::invalid_argument("Invalid sequence type");
        }
        copy->ensureCapacity();
        DynamicArray<T>* newItems = copy->items->Concat(other->items);
        Sequence<T>* result = new ArraySequence<T>(newItems->Get_data(), newItems->GetSize());
        delete newItems;
        return result;
    }
};

#endif // LAB2_ARRAYSEQUENCE_H
