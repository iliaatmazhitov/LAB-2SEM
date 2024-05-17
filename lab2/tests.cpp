//
// Created by Илья Атмажитов on 17.05.2024.
//

#include <iostream>

#include "DynamicArray.h"
#include "LinkedList.h"

void TEST_DA() {
    cout << "Testing DynamicArray..." << endl;

    DynamicArray<int> arr1(5);
    cout << "Array size after constructor with size: " << arr1.GetSize() << endl;

    int items[] = {1, 2, 3, 4, 5};
    DynamicArray<int> arr2(items, 5);
    cout << "Array contents after constructor with initializer list: ";
    arr2.Print();

    DynamicArray<int> arr3(arr2);
    cout << "Array contents after copy constructor: ";
    arr3.Print();

    arr3.Set(2, 10);
    cout << "Array contents after Set(2, 10): ";
    arr3.Print();
    cout << "Value at index 2: " << arr3.Get(2) << endl;

    cout << "First element: " << arr3.GetFirst() << endl;
    cout << "Last element: " << arr3.GetLast() << endl;

    arr3.Resize(8);
    cout << "Array size after Resize(8): " << arr3.GetSize() << endl;

    DynamicArray<int>* subArr = arr3.GetSubsequence(1, 4);
    cout << "Subsequence from index 1 to 4: ";
    subArr->Print();
    delete subArr;

    DynamicArray<int> arr4(3);
    arr4.Set(0, 10);
    arr4.Set(1, 20);
    arr4.Set(2, 30);
    DynamicArray<int>* concatArr = arr3.Concat(&arr4);
    cout << "Concatenated array: ";
    concatArr->Print();
    delete concatArr;

    cout << "Testing completed." << endl;
}


void TEST_LL() {
    cout << "Testing LinkedList..." << endl;

    int items[] = {1, 2, 3, 4, 5};
    LinkedList<int> ll1(items, 5);
    cout << "List contents after constructor with initializer list: ";
    ll1.Print();

    LinkedList<int> ll2(ll1);
    cout << "List contents after copy constructor: ";
    ll2.Print();

    cout << "First element: " << ll2.GetFirst() << endl;
    cout << "Last element: " << ll2.GetLast() << endl;
    cout << "Value at index 2: " << ll2.Get(2) << endl;

    ll2.Append(6);
    ll2.Prepend(0);
    cout << "List contents after Append(6) and Prepend(0): ";
    ll2.Print();

    ll2.Set(3, 10);
    cout << "List contents after Set(3, 10): ";
    ll2.Print();

    LinkedList<int>* subList = ll2.GetSubsequence(1, 4);
    cout << "Subsequence from index 1 to 4: ";
    subList->Print();
    delete subList;

    ll2.InsertAt(20, 3);
    cout << "List contents after InsertAt(20, 3): ";
    ll2.Print();

    LinkedList<int> ll3(3);
    ll3.Set(0, 100);
    ll3.Set(1, 200);
    ll3.Set(2, 300);
    LinkedList<int>* concatList = ll2.Concat(&ll3);
    cout << "Concatenated list: ";
    concatList->Print();
    delete concatList;

    ll2.Clear();
    cout << "List length after Clear(): " << ll2.GetLength() << endl;

    cout << "Testing completed." << endl;
}
