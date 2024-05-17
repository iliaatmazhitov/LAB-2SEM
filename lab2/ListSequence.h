//
// Created by Илья Атмажитов on 06.05.2024.
//

#ifndef LAB2_LISTSEQUENCE_H
#define LAB2_LISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"
#include <stdexcept>


template <class T> class ListSequence : public Sequence<T>{

private:
    LinkedList<T> *items;

public:

    ListSequence() {
        this->items = new LinkedList<T>;
    }

    ListSequence(T* items, int count) {
        this->items = new LinkedList<T>(items, count);
    }

    ListSequence(int count){
        this -> items = new LinkedList<T>(count);
    }

    virtual ~ListSequence() {
        this -> items -> Clear();
    }

    int GetLength() {
        return this->items->GetLength();
    }


    ListSequence<T>* GetCopy(){
        return new ListSequence<T>(*this);
    }

    Sequence<T>* AppendImmutable(T item){
        ListSequence<T>* copy = GetCopy();
        copy->items->Append(item);
        return copy;

    }

    Sequence<T>* Append(T item) {
        this->items->Append(item);
        return this;
    }

    Sequence<T>* SetImmutable(int index, T value){
        ListSequence<T>* copy = GetCopy();
        copy->items->Set(index, value);
        return copy;
    }

    Sequence<T>* Prepend(T item) {
        this->items->Prepend(item);
        return this;
    }

    Sequence<T>* PrependImmutable(T item){
        ListSequence<T>* copy = GetCopy();
        copy->items->Prepend(item);
        return copy;

    }

    Sequence<T>* InsertAt(T item, int index) {
        this->items->InsertAt(item, index);
        return this;
    }

    Sequence<T>* InsertAtImmutable(T item, int index){
        ListSequence<T>* copy = GetCopy();
        copy->items->InsertAt(item, index);
        return copy;
    }

    ListSequence(const ListSequence<T> & other) { // Конструктор копирования
        this -> items = new LinkedList<T>(*other.items);

    }

    void Print(){
        this->items->Print();
    }

    T Get(int index) {
        return this->items->Get(index);
    }

    T GetLast() {
        return this->items->GetLast();
    }

    T GetFirst() {
        return this->items->GetFirst();
    }

    Sequence<T>* Set(int index, T value){
        this->items->Set(index, value);
        return this;
    }

    Sequence<T>* Concat(Sequence<T>* list){

        ListSequence<T>* seq = new ListSequence<T>;
        ListSequence<T>* other = static_cast<ListSequence<T>*>(list);
        seq->items = this->items->Concat(other -> items);
        return seq;
    }

    Sequence<T>* ConcatImmutable(Sequence<T>* list){
        ListSequence<T>* copy = GetCopy();
        ListSequence<T>* seq = new ListSequence<T>;
        ListSequence<T>* other = static_cast<ListSequence<T>*>(list);
        seq->items = copy->items->Concat(other -> items);
        return seq;
    }

    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
        LinkedList<T>* subList = this->items->GetSubsequence(startIndex, endIndex);
        ListSequence<T>* subSequence = new ListSequence<T>;
        subSequence->items = subList;
        return subSequence;
    }


};

#endif //LAB2_LISTSEQUENCE_H
