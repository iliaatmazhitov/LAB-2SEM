#pragma once
#include "Sequence.h"
#include "LinkedList.h"
#include <stdexcept>


template <class T> class ListSequence : public Sequence<T> {

private:
    LinkedList<T>* items;

public:

    ListSequence() {
        this->items = new LinkedList<T>;
    }

    ListSequence(T* items, int count) {
        this->items = new LinkedList<T>(items, count);
    }

    ListSequence(int count) {
        this->items = new LinkedList<T>(count);
    }

    virtual ~ListSequence() {
        this->items->Clear();
    }

    int GetLength() const{
        return this->items->GetLength();
    }




    void Append(T item) {
        this->items->Append(item);

    }


    void Prepend(T item) {
        this->items->Prepend(item);
    }



    ListSequence(const ListSequence<T>& other) {
        this->items = new LinkedList<T>(*other.items);

    }


    T & Get(int index) {
        return this->items->Get(index);
    }

    T get(int index) const {
        return  this -> items -> Get(index);
    }

    T GetLast() const {
        return this->items->GetLast();
    }

    T GetFirst() const{
        return this->items->GetFirst();
    }

    void Set(int index, T value) {
        this->items->Set(index, value);
    }




};

