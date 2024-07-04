#pragma once

#include <stdexcept>

template <class T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(const T& new_value, Node* new_prev = nullptr, Node* new_next = nullptr) :
                value(new_value), next(new_next), prev(new_prev) {}
    };
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(T* items, int count) : LinkedList() {
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    LinkedList(int count) : head(nullptr), tail(nullptr), length(0) {
        if (count < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }

        for (int i = 0; i < count; ++i) {
            Append(T());
        }
    }

    LinkedList(const LinkedList <T>& list) : LinkedList() {
        Node* current = list.head;
        while (current != nullptr) {
            Append(current->value);
            current = current->next;
        }
    }

    ~LinkedList() {
        Clear();
    }

    T GetFirst() const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->value;
    }

    T GetLast() const {
        if (tail == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return tail->value;
    }

    T & Get(int index)  {
        if (index > length || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    T get(int index) const {
        if (index >= length || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }


    int GetLength() const {
        return length;
    }

    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void Append(const T& item) {
        Node* node = new Node(item);
        if (length == 0) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        length++;
    }

    void Prepend(const T& item) {
        Node* node = new Node(item);
        if (length == 0) {
            head = tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        length++;
    }

    void Set(int index, T value) {
        if (index >= length || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->value = value;
    }


    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (&other == this) {
            return *this;
        }

        Clear();
        Node* current = other.head;
        while (current != nullptr) {
            Append(current->value);
            current = current->next;
        }
        return *this;
    }
};




