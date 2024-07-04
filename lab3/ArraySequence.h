#pragma once



#include "DynamicArray.h"
#include "Sequence.h"


using namespace std;


template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;

public:
    ArraySequence() {
        this->items = new DynamicArray<T>;
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(T* items, int count) {
        this->items = new DynamicArray<T>(items, count);
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(int size) {
        this->items = new DynamicArray<T>(size);
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(const ArraySequence<T>& other) { // Конструктор копирования
        this->items = new DynamicArray<T>(*other.items);
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ~ArraySequence() {
        if (this->items != nullptr) {
            delete this->items;
        }
    }

    int GetLength() const{
        return this->items->GetSize();
    }

    T & Get(int index) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }

    T get (int index) const {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }


    T GetLast() const{
        if (GetLength() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetLast();
    }

    T GetFirst() const{
        if (GetLength() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetFirst();
    }

    void Set(int index, T value) {
        if (index < 0 || index >= GetLength()) {
            throw std::out_of_range("Invalid index");
        }
        this->items->Set(index, value);
    }

    void Append(T item) {
        this->items->Resize(this->items->GetSize() + 1);
        this->items->Set(this->items->GetSize() - 1, item);
    }

    void Prepend(T item) {
        int size = this->items->GetSize();
        DynamicArray<T>* oldArray = this->items;

        this->items = new DynamicArray<T>(size + 1);
        if (this->items == nullptr) {
            delete oldArray;
            throw logic_error("");
        }

        for (int i = 0; i < size; i++) {
            this->items->Set(i + 1, oldArray->Get(i));
        }

        this->items->Set(0, item);

        delete oldArray;
    }


    ArraySequence<T>* GetCopy() {
        return new ArraySequence<T>(*this);
    }

};
