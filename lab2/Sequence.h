//
//  Sequence.h
//  laboratory2
//
//  Created by Илья Атмажитов on 25.04.2024.
//

#pragma once

using namespace std;

template <class T> class Sequence {
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;

    virtual int GetLength() = 0;

    virtual Sequence<T>* Set(int index, T data) = 0;
    virtual Sequence<T>* SetImmutable(int index, T data) = 0;

    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* AppendImmutable(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* PrependImmutable(T item) = 0;

    virtual Sequence<T>* InsertAt(T item, int index) = 0;
    virtual Sequence<T>* InsertAtImmutable(T item, int index) = 0;
    virtual void Print() = 0;

    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    virtual Sequence <T>* ConcatImmutable(Sequence <T>* list) = 0;

//    virtual Sequence<T>* GetCopy() = 0;

};





