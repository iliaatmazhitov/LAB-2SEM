//
//  UI.cpp
//  laboratory4
//
//  Created by Илья Атмажитов on 27.05.2024.
//


#include <iostream>
#include <string>
#include "tree.h"
#include "UI.h"
#include "functions.h"
#include "generate.h"
#include "tests.h"


using namespace std;



void displayUI() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "1. Выберите тип данных данных." << endl;
    cout << "2. Выберите функцию." << endl;
    cout << "3. Тесты программы" << endl;
    cout << "0. Выйти." << endl;
    cout << "________________________________________________________________________________" << endl;
}

void type_of_data() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "_______________________________Введите тип данных_______________________________" << endl;
    cout << "1. Целые числа." << endl;
    cout << "2. Строки." << endl;
    cout << "________________________________________________________________________________" << endl;
}

void func() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "________________________________Выберите функцию________________________________" << endl;
    cout << "1. Поиск." << endl;
    cout << "2. Удаление." << endl;
    cout << "3. Балансировка." << endl;
    cout << "4. Map." << endl;
    cout << "5. Where." << endl;
    cout << "6. Reduce." << endl;
    cout << "7. Извлечение поддерева." << endl;
    cout << "8. Поиск на вхождение." << endl;
    cout << "9. Удалить дерево." << endl;
    cout << "10. Вывод дерева." << endl;
    cout << "11. Добавление элемента." << endl;
    cout << "________________________________________________________________________________" << endl;
}





void your_choice() {
    int choice_ui, type = 0, func_type;
    
    BST<int> tree_int;
    BST<string> tree_string;
    
    while(1) {
        displayUI();
        
        choice_ui = input(0, 3);
        
        if (choice_ui == 1) {
            type_of_data();
            type = input(1, 2);
            
        } else if (choice_ui == 2) {
            func();
            
            func_type = input(1, 11);
            
            if (func_type == 1) {
                if (type == 1) {
                    int elem;
                    cout << "Введите элемент для проверки: ";
                    cin >> elem;
                    if (tree_int.find_elem(elem)) {
                        cout << "Элемент найден в дереве." << endl;
                    } else {
                        cout << "Элемент не найден в дереве." << endl;
                    }
                } else if (type == 2) {
                    string elem;
                    cout << "Введите элемент для проверки: ";
                    cin >> elem;
                    if (tree_string.find_elem(elem)) {
                        cout << "Элемент найден в дереве." << endl;
                    } else {
                        cout << "Элемент не найден в дереве." << endl;
                    }
                }
                
            } else if (func_type == 2) {
                if (type == 1) {
                    int elem;
                    cout << "Введите элемент для удаления:";
                    cin >> elem;
                    tree_int.remove(elem);
                    
                } else if (type == 2) {
                    string elem;
                    cout << "Введите элемент для удаления:";
                    cin >> elem;
                    tree_string.remove(elem);
                }
                
            } else if (func_type == 3) {
                if (type == 1) {
                    tree_int.balanceTree();
                } else if (type == 2) {
                    tree_string.balanceTree();
                }
                
            } else if (func_type == 4) { // Map
                if (type == 1) {
                    tree_int.map(multiply_by_2, type);
                    
                } else if (type == 2) {
                    tree_string.map(plus_A, type);
                }
                
            } else if (func_type == 5) { // Where
                if (type == 1) {
                    tree_int.where(is_onedigit, type);
                } else if (type == 2) {
                    tree_string.where(is_polyndrome, type);
                }
                
            } else if (func_type == 6) { // Reduce
                if (type == 1) {
                    cout << tree_int.reduce(sum);
                } else if (type == 2) {
                    cout << tree_string.reduce(sum);
                }
                
            } else if (func_type == 7) { // Извлечение поддерева
                if (type == 1) {
                    int data;
                    cout << "Введите элемент:";
                    cin >> data;
                    tree_int.subtree(data);
                } else if (type == 2) {
                    string data;
                    cout << "Введите элемент:";
                    cin >> data;
                    tree_string.subtree(data);
                }
                
            } else if (func_type == 8) {
                if (type == 1) {
                    BST<int> subroot;
                    int n;
                    cout << "Введите кол-во элементов";
                    cin >> n;
                    int elem;
                    for (int i = 0; i < n; i++) {
                        cout << "Введите элемент:";
                        cin >> elem;
                        subroot.add(elem);
                    }
                    
                    cout << tree_int.is_subtree(subroot) << endl;
                } else if (type == 2) {
                    BST<string> subroot;
                    int n;
                    cout << "Введите кол-во элементов";
                    cin >> n;
                    string elem;
                    for (int i = 0; i < n; i++) {
                        cout << "Введите элемент:";
                        cin >> elem;
                        subroot.add(elem);
                    }
                    
                    cout << tree_string.is_subtree(subroot) << endl;
                }
                
                
            } else if (func_type == 9) { // Очистка дерева
                
                if (type == 1) {
                    tree_int.clear_UI();
                    
                } else if (type == 2) {
                    tree_string.clear_UI();
                    
                }
                
                
            } else if (func_type == 10) { // Вывод дерева
                
                if (type == 1) {
                    tree_int.print_tree_branches();
                    
                } else if (type == 2) {
                    tree_string.print_tree_branches();
                }
                
                
            } else if (func_type == 11) { // Добавление элемента
                if (type == 1) {
                    int n;
                    cout << "Введите кол-во элементов";
                    cin >> n;
                    int elem;
                    for (int i = 0; i < n; i++) {
                        cout << "Введите элемент:";
                        cin >> elem;
                        tree_int.add(elem);
                    }
                    
                } else if (type == 2) {
                    int n;
                    cout << "Введите кол-во элементов";
                    cin >> n;
                    string elem;
                    for (int i = 0; i < n; i++) {
                        cout << "Введите элемент:";
                        cin >> elem;
                        tree_string.add(elem);
                    }
                }
            }
            
            
            
        }  else if (choice_ui == 3) {
            testBST();

        } else if (choice_ui == 0) {
            break;
        }
    }
    
}

