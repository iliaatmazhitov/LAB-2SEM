#pragma once

using namespace std;


template <class T> class Sequence {
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const= 0;
    virtual T & Get(int index) = 0;
    virtual T get(int  index) const = 0;

    virtual int GetLength() const = 0 ;

    virtual void Set(int index, T data) = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;

    virtual ~Sequence(){};

};

