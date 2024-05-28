#include <iostream>
#include "tests.h"
#include "tree.h"

using namespace std;

void testBST() {
    BST<int> bst1;

    // Тест для пустого дерева
    string traversal = bst1.fix_traversal();
    if (traversal.empty()) {
        cout << "Test for empty tree passed." << endl;
    } else {
        cout << "Test for empty tree failed." << endl;
    }

    // Тест для добавления элементов
    bst1.add(5);
    bst1.add(3);
    bst1.add(7);
    bst1.add(1);
    bst1.add(9);
    traversal = bst1.fix_traversal();
    if (traversal == "1 3 5 7 9 ") {
        cout << "Test for adding elements passed." << endl;
    } else {
        cout << "Test for adding elements failed. Expected: 1 3 5 7 9, Got: " << traversal << endl;
    }

    // Тест для поиска существующего элемента
    if (bst1.find_elem(3)) {
        cout << "Test for finding existing element passed." << endl;
    } else {
        cout << "Test for finding existing element failed." << endl;
    }

    // Тест для поиска несуществующего элемента
    if (!bst1.find_elem(8)) {
        cout << "Test for not finding non-existent element passed." << endl;
    } else {
        cout << "Test for not finding non-existent element failed." << endl;
    }

    // Тест для удаления элемента
    traversal = bst1.fix_traversal();
    bst1.remove(3);
    traversal = bst1.fix_traversal();
    if (traversal == "1 5 7 9 ") {
        cout << "Test for removing element passed." << endl;
    } else {
        cout << "Test for removing element failed. Expected: 1 5 7 9, Got: " << traversal << endl;
    }

    // Тест для очистки дерева
    bst1.clear_UI();
    traversal = bst1.fix_traversal();
    if (traversal.empty()) {
        cout << "Test for clearing tree passed." << endl;
    } else {
        cout << "Test for clearing tree failed." << endl;
    }
}

