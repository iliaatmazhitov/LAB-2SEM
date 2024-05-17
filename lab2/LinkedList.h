//
//  LinkedList.h
//  laboratory2
//
//  Created by Илья Атмажитов on 12.04.2024.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <stdexcept>


template <class T> 

class LinkedList{
private:
    struct Node{ 
        T value;
        Node* next;
        Node* prev;
        Node(const T& new_value, Node* new_prev = nullptr, Node* new_next = nullptr):
        value(new_value), next(new_next), prev(new_prev){}
    };
    Node* head;
    Node* tail;
    int length;
    
public:
    LinkedList(): head(nullptr), tail(nullptr), length(0) {}
    
    LinkedList (T* items, int count): LinkedList(){
        for (int i = 0; i < count; i++){
            Append(items[i]);
        }
    }

    LinkedList(int count) {
        head = nullptr;
        tail = nullptr;
        length = 0;

        if (count < 0) {
            throw invalid_argument("Size cannot be negative");
        }

        if (count == 0) {
            return;
        }

        // Создаем первый узел
        Node* newNode = new Node(T());
        head = newNode;
        tail = newNode;
        length = 1;

        // Создаем остальные узлы
        for (int i = 1; i < count; ++i) {
            Node* newNode = new Node(T());
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            length++;
        }
    }

    
    LinkedList (const LinkedList <T> & list): LinkedList(){
        Node* current = list.head;
        while (current != nullptr){
            Append(current -> value);
            current = current -> next;
        }
        
    }
    
    ~LinkedList(){
        Clear();
    }
    
    T GetFirst() const{
        if (head == nullptr){
            throw out_of_range("");
        }
        return head -> value;
    }


    T GetLast() const{
        if (tail == nullptr){
            throw out_of_range("");
        }
        return tail -> value;
    }


    T Get(int index) const{
        if (index >= length || index < 0){
            throw out_of_range("");
        }
        Node* current = head;
        for (int i = 0; i < index; i++){
            current = current -> next;
        }
        return current -> value;
    }


    LinkedList<T>* GetSubsequence(int startIndex, int endIndex) {
        int size = GetLength();

        if (startIndex < 0 || startIndex >= size ||
            endIndex < 0 || endIndex >= size ||
            startIndex > endIndex) {
            throw std::out_of_range("");
        }

        LinkedList<T>* subList = new LinkedList<T>;

        Node* current = head;
        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            subList->Append(current->value);
            current = current->next;
        }

        return subList;
    }


    int GetLength() const {
        return length;
    }
    
    void Clear(){
        Node* current;
        Node* old;
        current = head;
        for (int i = 0; i < length; i++){
            old = current;
            current = current -> next;
            delete old;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void Append(const T& item){
        Node* node = new Node(item);
        if (length == 0){
            head = tail = node;
            length += 1;
            return;
        }
        tail -> next = node;
        node -> prev = tail;
        tail = node;
        length += 1;
        
    }

    void Prepend(const T& item){
        Node* node = new Node(item);
        if (length == 0){
            head = tail = node;
            length += 1;
            return;
        }
        head -> prev = node;
        node -> next = head;
        head = node;
        length += 1;

    }

    void Set(int index, T value){
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        current -> value = value;
    }
    
    void InsertAt(const T& item, int index) {
        if (index > length || index < 0) {
            throw out_of_range("");
        }

        if (index == 0) {
            Prepend(item);
            return;
        }

        if (index == length) {
            Append(item);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node* node = new Node(item);

        Node* next = current->next; // Сохраняет ссылку на след узел после каррента в переменной некст
        current->next = node; // указатель некст текущего узла теперь ссылается на новый узел
        node->prev = current; // указатель прев нового узла теперь ссылается на каррент
        node->next = next; // указатель нового узла некст ссылается на некст
        next->prev = node;
        length++;
    }


    LinkedList<T>* Concat(LinkedList<T>* list) {
        // Создаем новый пустой список
        LinkedList<T>* newList = new LinkedList<T>();

        // Добавляем элементы из текущего списка в новый список
        Node* current = head;
        while (current != nullptr) {
            newList->Append(current->value);
            current = current->next;
        }

        // Добавляем элементы из переданного списка в новый список
        current = list->head;
        while (current != nullptr) {
            newList->Append(current->value);
            current = current->next;
        }

        return newList;
    }
    
    void Print() const{
        if (length == 0) {
            throw out_of_range("");
        }

        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
    
    LinkedList<T> & operator=(const LinkedList<T> & other){
        if (&other == this){
            return *this;
        }
        
        Clear();
        Node* current = other.head;
        while (current != nullptr){
            Append(current -> value);
            current = current -> next;
        }
        return *this;
    }
};




#endif /* LinkedList_h */
