//
// Created by Илья Атмажитов on 07.05.2024.
//

#pragma once

#include <iostream>
#include <exception>
#include "generate.h"
#include "ArraySequence.h"
#include "UI.h"


using namespace std;


template <class T>
class BST {
private:
    struct Node {
        T key;
        Node *right;
        Node *left;

        Node(const T &item = T()) : key(item), right(nullptr), left(nullptr) {}
    };

    Node *root;

    // Вспомогательная функция для рекурсивного вывода дерева
    void printBT(const string &prefix, const Node *node, bool isLeft) const {
        if (node != nullptr) {
            cout << prefix;
            cout << (isLeft ? "├──" : "└──");
            cout << node->key << endl;
            printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

public:

    BST() : root(nullptr) {}

    BST(int size, T (*generate)()) : BST() {
        for (int i = 0; i < size; i++) {
            add(generate());
        }
    }

    ~BST() {
        clear(root);
    }


    void clear(Node *node) {
        if (node == nullptr) {
            return;
        }
        
        if (node -> right == nullptr) {
            return;
        }
        
        if (node -> left == nullptr) {
            return;
        }
        
        clear(node -> left);
        clear(node -> right);
        delete node;
    }
    


    void add(const T &item) {
        Node *new_node = new Node(item);

        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node *current = root;
        while (current->key != item) {
            if (current->key > item) {
                if (current->left == nullptr) {
                    current->left = new_node;
                    return;
                }

                current = current->left;

            } else if (current->key < item) {
                if (current->right == nullptr) {
                    current->right = new_node;
                    return;
                }

                current = current->right;

            }
        }

    }
    
    void remove(const T& item) {
        
        if (root == nullptr) {
            return;
        }
        
        root = del(root, item);
        
    }


    Node* del(Node* node, const T& item) {
        if (node == nullptr) {
            return node;
        }

        if (item < node->key) {
            node->left = del(node->left, item);
            
        } else if (item > node->key) {
            node->right = del(node->right, item);
            
        } else {
            // Узел не имеет потомков
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            
            // Узел имеет потомка (правого или левого)
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
                
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Узел имеет двух потомков
            else {
                Node* minNode = min_node(node->right);
                node->key = minNode->key;
                node->right = del(node->right, minNode->key);
                return node;
            }
        }

        return node;
    }
    

    
    bool find_elem(const T &elem) {
        Node *current = root;

        while (current != nullptr) {
            if (current->key == elem) {
                return true;
            } else if (current->key > elem) {
                current = current-> left;
            } else {
                current = current->right;
            }
        }

        return false;
    }
    
    Node* find_node(const T  & elem) {
        
        Node *current = root;

        while (current != nullptr) {
            if (current->key == elem) {
                return current;
            } else if (current->key > elem) {
                current = current-> left;
            } else {
                current = current->right;
            }
        }

        return nullptr;
        
    }

    T max() const {
        Node* new_node = root;
        
        if (root == nullptr) {
            throw invalid_argument("");
        }
        
        if (new_node -> right == nullptr) {
            return new_node -> key;
        }
        
        else {
            while(new_node -> right != nullptr) {
                new_node = new_node -> right;
            }
        }
        return new_node -> key;
    }
    
    
    string fix_traversal() {
        return toString("ЛКП");
    }
    
    // Функция для получения отсортированного вектора ключей из дерева
    void inorderTraversal(Node* node, ArraySequence<T>& keys) {
        if (node != nullptr) {
            inorderTraversal(node->left, keys);
            keys.Append(node->key);
            inorderTraversal(node->right, keys);
        }
    }

    // Функция для построения сбалансированного дерева из отсортированного вектора
    Node* buildBalancedBST(ArraySequence<T>& keys, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Node* node = new Node(keys.Get(mid));

        node->left = buildBalancedBST(keys, start, mid - 1);
        node->right = buildBalancedBST(keys, mid + 1, end);

        return node;
    }

    // Функция для балансировки дерева
    void balanceTree() {
        ArraySequence<T> keys;
        inorderTraversal(root, keys);
        root = buildBalancedBST(keys, 0, keys.GetLength() - 1);
    }
    
    
    
    string toString(string traversal, Node *leaf = nullptr, bool isFirst = true)
    {
        static string ans = "";
        
        if(isFirst){
            ans = "";
            leaf = root;
        }
        
        
        if (leaf)
        {
            if(traversal == "КЛП"){
                ans += to_string(leaf->key) + " ";
                toString(traversal, leaf->left, false);
                toString(traversal, leaf->right, false);
            }
            else if(traversal == "КПЛ"){
                ans += to_string(leaf->key) + " ";
                toString(traversal, leaf->right, false);
                toString(traversal, leaf->left, false);
            }
            else if(traversal == "ЛПК"){
                toString(traversal, leaf->left, false);
                toString(traversal, leaf->right, false);
                ans += to_string(leaf->key) + " ";
            }
            else if(traversal == "ЛКП"){
                toString(traversal, leaf->left, false);
                ans += to_string(leaf->key) + " ";
                toString(traversal, leaf->right, false);
            }
            else if(traversal == "ПЛК"){
                toString(traversal, leaf->right, false);
                toString(traversal, leaf->left, false);
                ans += to_string(leaf->key) + " ";
            }
            else if(traversal == "ПКЛ"){
                toString(traversal, leaf->right, false);
                ans += to_string(leaf->key) + " ";
                toString(traversal, leaf->left, false);
            }
        
        }
        return ans;
    }
    
    Node* max_node(Node* node) const {
        
        Node* current = node;
        
        if (current == nullptr) {
            throw invalid_argument("");
        }
        
        while (current && current->right != nullptr) {
            current = current->right;
        }
        
        
        return current;
    
    }

    T min() const {
        Node* new_node = root;
        
        if (root == nullptr) {
            throw invalid_argument("");
        }
        
        if (new_node -> left == nullptr) {
            return new_node -> key;;
        }
        else {
            while(new_node -> left != nullptr) {
                new_node = new_node -> left;
            }
        }
        return new_node -> key;
    }
    
    Node* min_node(Node* node) const {
        
        Node* current = node;
        
        if (current == nullptr) {
            throw invalid_argument("");
        }
        
        while (current && current->left != nullptr) {
            current = current->left;
        }
        
        
        return current;
    
    }


    // Оригинальная функция print для сравнения
    void print(Node *node, int indent) const {
        if (node == nullptr) {
            return;
        }

        cout << string(indent * 4, ' ') << node->key << endl;
        print(node->left, indent + 1);
        print(node->right, indent + 1);

    }

    void print_tree() const {

        print(root, 0);
    }

    // Функция для вывода дерева с использованием символов /
    void print_tree_branches() const {
        printBT("", root, false);
    }
    
    
    void map_recursive_int(Node* node, T (*func)(T)) {
        if (node != nullptr) {
            node->key = func(node->key);
            map_recursive_int(node->left, func);
            map_recursive_int(node->right, func);
        }
    }
    
    void map_recursive_string(Node* node, T (*func)(T)) {
        if (node != nullptr) {
            node->key = func(node->key);
            map_recursive_string(node->left, func);
            map_recursive_string(node->right, func);
        }
    }

    
    void map(T (*func)(T), int type) {
        
        if (type == 1){ // int
            map_recursive_int(root, func);
        }
        
        else { // string
            map_recursive_string(root, func);
        }
    }
    
    
    void where_recursive_int(Node* node, bool (*func)(T)) {
         if (node != nullptr) {
             where_recursive_int(node->left, func);
             where_recursive_int(node->right, func);

             if (func(node -> key)) {
                 node -> key += 1;
             }
         }

     }

     void where_recursive_string(Node* node, bool (*func)(T)) {
         if (node != nullptr) {
             where_recursive_string(node->left, func);
             where_recursive_string(node->right, func);

             if (func(node -> key)) {
                 node -> key += 'R';
             }
         }

     }
    
    void where(bool (*func)(T), int type) {
        
        
        if (type == 1) { // int
            where_recursive_int(root, func);
        }
        
        else if (type == 2){ // string
            where_recursive_string(root, func);
        }
    
    }
    
    
    T reduce_recursive(Node* node, T (*func)(T, T)) const {
        if (node == nullptr) {
            return T();
        }
        
        T leftRes = reduce_recursive(node->left, func);
        T rightRes = reduce_recursive(node->right, func);
        return func(func(node->key, leftRes), rightRes);
    
    }

    
    T reduce(T (*func)(T, T)) const {
        return reduce_recursive(root, func);
    }
    
    Node* subtree_recursive(Node* node) {
        Node* newRoot = nullptr;
        
        if (node != nullptr) {
            newRoot = new Node(node -> key);
            newRoot -> left = subtree_recursive(node -> left);
            newRoot -> right = subtree_recursive(node -> right);
        }
        else {
            return nullptr;
        }
        
        return newRoot;
        
    }
    
    void subtree(T data) {
        
        Node* result = subtree_recursive(find_node(data));
        printBT("", result, false);
        
    }
    

    bool is_subtree(BST subroot) const {
        return is_subtree_recursive(root, subroot.root);
    }

    bool is_subtree_recursive(Node* node, Node* subroot) const {
        if (subroot == nullptr) {
            return true;
        }
        if (node == nullptr) {
            return false;
        }
        if (node->key == subroot->key && isSameTree(node, subroot)) {
            return true;
        }
        return is_subtree_recursive(node->left, subroot) || is_subtree_recursive(node->right, subroot);
    }

    bool isSameTree(Node* node1, Node* node2) const {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        return node1->key == node2->key && isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
    }
        
    
    void clear_UI() {
        clear(root);
        root = nullptr; // Устанавливаем корень в nullptr после очистки
    }
    
};
