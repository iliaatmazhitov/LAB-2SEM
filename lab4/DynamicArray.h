//
//  DynamicArray.h
//  laboratory4
//
//  Created by Илья Атмажитов on 26.05.2024.
//

#ifndef DynamicArray_h
#define DynamicArray_h



#include <iostream>
#include <stdexcept>

using namespace std;


template<class T>
class DynamicArray {
private:
    T* data;
    int size;
    
public:
    DynamicArray(): data(nullptr), size(0) {}

    DynamicArray(T* items, int count) {
        size = count;
        data = new T[size];
        for (int i = 0; i < size; i++){
            data[i] = items[i];
        }
    }

    DynamicArray(int size) {
        if (size < 0) {
            throw invalid_argument("");
        }
        this->size = size;
        data = new T[size];
    }


    
    DynamicArray(const DynamicArray<T> & dynamicArray) {
        size = dynamicArray.size;
        data = new T[size];
        for (int i = 0; i < size; i++){
            data[i] = dynamicArray.data[i];
        }
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    T Get(int index) {
        if (index < 0 || index >= size){
            throw out_of_range("");
        }
        
        return data[index];
    }
    
    T GetFirst(){
        if (size == 0){
            throw out_of_range("");
        }
        
        return data[0];
    }
    
    T GetLast(){
        if (size == 0){
            throw out_of_range("");
        }
        
        return data[size - 1];
    }

    T* Get_data() const{
        return data;
    }
    
    int GetSize() {
        return size;
    }
    
    void Set(int index, T value){
        if (index < 0 || index > size){
            throw out_of_range("");
        }
        
        data[index] = value;
    }

    void Resize(int newSize){
        if (newSize < 0) {
            throw invalid_argument("");
        }

        if (newSize > size){
            T* oldData = data;
            data = new T[newSize];

            for (int i = 0; i < size; i++){
                data[i] = oldData[i];
            }

            delete[] oldData;
        }

        size = newSize;
    }

    DynamicArray<T>* GetSubsequence(int startIndex, int endIndex) {

        if (data == nullptr) {
            throw logic_error("Source array is null");
        }

        int size = GetSize();

        if (startIndex < 0 || startIndex >= size ||
            endIndex < 0 || endIndex >= size ||
            startIndex > endIndex) {
            throw out_of_range("");
        }

        int subSize = endIndex - startIndex + 1;
        T* subData = new T[subSize];

        for (int i = 0; i < subSize; i++) {
            subData[i] = Get(startIndex + i);
        }

        DynamicArray<T>* subSequence = new DynamicArray<T>(subData, subSize);
        delete[] subData;

        return subSequence;
    }


    void Print() const{
        for (int i = 0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    DynamicArray<T>* Concat(DynamicArray<T>* list) {
        int newSize = size + list->GetSize();
        DynamicArray<T>* result = new DynamicArray<T>(newSize);

        for (int i = 0; i < size; i++) {
            result->Set(i, data[i]);
        }

        for (int i = 0; i < list->GetSize(); i++) {
            result->Set(size + i, list->Get(i));
        }

        return result;
    }
    
    DynamicArray& operator= (const DynamicArray & other){
        if (&other != this){
            size = other.size;
            delete[] data;
            data = new T[size];
            
            for(int i = 0; i < size; i++){
                data[i] = other.data[i];
            }
        }
        
        return *this;
    }
};
    

#endif /* DynamicArray_h */


