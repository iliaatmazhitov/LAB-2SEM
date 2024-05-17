#include <iostream>
#include <string.h>
#include "UI.h"
#include "Sequence.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "tests.h"

using namespace std;

void displayUI() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "1. Выберите тип данных." << endl;
    cout << "2. Выберите структуру данных." << endl;
    cout << "3. Тесты программы." << endl;
    cout << "4. Выйти." << endl;
    cout << "________________________________________________________________________________" << endl;
}

void DA_UI() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "________________________________Создание объекта________________________________" << endl;
    cout << "1. Копировать элементы из массива." << endl;
    cout << "2. Получить элемент по индексу." << endl;
    cout << "3. Создать массив заданной длины." << endl;
    cout << "4. Получить первый элемент массива." << endl;
    cout << "5. Получить последний элемент массива." << endl;
    cout << "6. Получить массив из всех элементов в диапозоне." << endl;
    cout << "7. Получить длину массива." << endl;
    cout << "____________________________________Операции____________________________________" << endl;
    cout << "8. Задать элемент по индексу (Mutable)." << endl;
    cout << "9. Задать элемент по индексу (Immutable)." << endl;
    cout << "10. Добавить элемент в конец массива (Mutable)." << endl;
    cout << "11. Добавить элемент в конец массива (Immutable)." << endl;
    cout << "12. Добавить элемент в начало массива (Mutable)." << endl;
    cout << "13. Добавить элемент в начало массива (Immutable)." << endl;
    cout << "14. Конкатенация двух массивов (Mutable)." << endl;
    cout << "15. Конкатенация двух массивов (Immutable)." << endl;
    cout << "16. Вставить элемент в заданную позицию (Mutable)." << endl;
    cout << "17. Вставить элемент в заданную позицию (Immutable)." << endl;
    cout << "18. Вывести массив." << endl;
    cout << "19. Выйти." << endl;
    cout << "________________________________________________________________________________" << endl;
}

void T_UI(){
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "_________________________________Тесты структур_________________________________" << endl;
    cout << "1. Динамический массив." << endl;
    cout << "2. Связанный список." << endl;
    cout << "3. Выйти." << endl;
    cout << "________________________________________________________________________________" << endl;

}



void LL_UI() {
    cout << endl << "________________________________________________________________________________" << endl;
    cout << "________________________________Создание объекта________________________________" << endl;
    cout << "1. Копировать элементы из массива." << endl;
    cout << "2. Создать массив заданной длины." << endl;
    cout << "3. Получить первый элемент в списке." << endl;
    cout << "4. Получить последний элемент в списке." << endl;
    cout << "5. Получить элемент по индексу." << endl;
    cout << "6. Получить список из всех элементов в диапазоне." << endl;
    cout << "7. Получить длину списка." << endl;
    cout << "____________________________________Операции____________________________________" << endl;
    cout << "____________________________________Операции____________________________________" << endl;
    cout << "8. Задать элемент по индексу (Mutable)." << endl;
    cout << "9. Задать элемент по индексу (Immutable)." << endl;
    cout << "10. Добавить элемент в конец массива (Mutable)." << endl;
    cout << "11. Добавить элемент в конец массива (Immutable)." << endl;
    cout << "12. Добавить элемент в начало массива (Mutable)." << endl;
    cout << "13. Добавить элемент в начало массива (Immutable)." << endl;
    cout << "14. Конкатенация двух массивов (Mutable)." << endl;
    cout << "15. Конкатенация двух массивов (Immutable)." << endl;
    cout << "16. Вставить элемент в заданную позицию (Mutable)." << endl;
    cout << "17. Вставить элемент в заданную позицию (Immutable)." << endl;
    cout << "18. Вывести массив." << endl;
    cout << "19. Выйти." << endl;
    cout << "________________________________________________________________________________" << endl;
}


int input(int min, int max) {
    int answer;
    cin >> answer;
    while (answer < min || answer > max) {
        cout << "Ошибка. Введите число от " << min << " до " << max << endl;
        cin >> answer;
    }

    return answer;
}

void your_choice() {

    Sequence<int>* sequence_int;
    Sequence<double>* sequence_double;
    Sequence<string>* sequence_string;


    Sequence<int>* concat_int;
    Sequence<double>* concat_double;
    Sequence<string>* concat_string;



    int type = 0, choice_type_struct, choice_struct;

    while (1) {
        displayUI();

        choice_type_struct = input(1, 4);


        if (choice_type_struct == 1) {

            cout << endl << "________________________________________________________________________________" << endl;
            cout << "1. Целые числа." << endl;
            cout << "2. Вещественные числа." << endl;
            cout << "3. Строки." << endl;
            cout << "________________________________________________________________________________" << endl;

            type = input(1, 3);

        } else if (choice_type_struct == 2) {

            cout << endl << "________________________________________________________________________________" << endl;
            cout << "1. Динамический массив." << endl;
            cout << "2. Связанный список." << endl;
            cout << "________________________________________________________________________________" << endl;

            choice_struct = input(1, 2);

            if (choice_struct == 1) {
                if (type == 1) {
                    sequence_int = new ArraySequence<int>;
                    concat_int = new ArraySequence<int>;
                }
                if (type == 2) {
                    sequence_double = new ArraySequence<double>;
                    concat_double = new ArraySequence<double>;
                }
                if (type == 3) {
                    sequence_string = new ArraySequence<string>;
                    concat_string = new ArraySequence<string>;
                }

            } else if (choice_struct == 2) {
                if (type == 1) {
                    sequence_int = new ListSequence<int>;
                    concat_int = new ListSequence<int>;
                }
                if (type == 2) {
                    sequence_double = new ListSequence<double>;
                    concat_double = new ListSequence<double>;
                }
                if (type == 3) {
                    sequence_string = new ListSequence<string>;
                    concat_string = new ListSequence<string>;
                }

            }

            while (1) {

                if (choice_struct == 1) {

                    DA_UI();

                    // Переменная для выбора для Динамического массива
                    int da_operation;
                    da_operation = input(1, 19);

                    if (da_operation == 1) {
                        // Копировать элементы из массива

                        cout << "Введите размер массива: ";

                        int size;
                        cin >> size;

                        if (type == 1) {

                            int *temp = new int[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_int = new ArraySequence<int>(temp, size);

                            delete[] temp;

                        } else if (type == 2) {

                            double *temp = new double[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_double = new ArraySequence<double>(temp, size);

                            delete[] temp;

                        } else {

                            string *temp = new string[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_string = new ArraySequence<string>(temp, size);

                            delete[] temp;
                        }


                    } else if (da_operation == 2) { // Получить элемент по индексу
                        int index;
                        cout << "Введите индекс: ";
                        cin >> index;

                        if (type == 1) {
                            cout << sequence_int->Get(index) << endl;
                        } else if (type == 2) {
                            cout << sequence_double->Get(index) << endl;
                        } else {
                            cout << sequence_string->Get(index) << endl;
                        }


                    } else if (da_operation == 3) { // Создать массив заданной длины.
                        int size;
                        cout << "Введите размер массива: ";
                        cin >> size;
                        if (type == 1) {
                            sequence_int = new ArraySequence<int>(size);
                        }
                        if (type == 2) {
                            sequence_double = new ArraySequence<double>(size);
                        }
                        if (type == 3) {
                            sequence_string = new ArraySequence<string>(size);
                        }

                    } else if (da_operation == 4) { // Получить первый элемент массива
                        if (type == 1) {
                            cout << sequence_int->GetFirst();
                        } else if (type == 2) {
                            cout << sequence_double->GetFirst();
                        } else if (type == 3) {
                            cout << sequence_string->GetFirst();
                        }


                    } else if (da_operation == 5) { // Получить последний элемент массива
                        if (type == 1) {
                            cout << sequence_int->GetLast();
                        } else if (type == 2) {
                            cout << sequence_double->GetLast();
                        } else if (type == 3) {
                            cout << sequence_string->GetLast();
                        }

                    } else if (da_operation == 6) { // Получить массив из всех элементов в диапазоне
                        int start;
                        int end;
                        cout << "Введите диапазон: ";
                        cin >> start >> end;

                        if (type == 1) {
                            Sequence<int> *subSequence;
                            subSequence = static_cast<ArraySequence<int>*>(sequence_int->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_int->Get(i) << " ";
                            }
                            delete subSequence;
                        } else if (type == 2) {
                            Sequence<double> *subSequence;
                            subSequence = static_cast<ArraySequence<double>*>(sequence_double->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_double->Get(i) << " ";
                            }
                            delete subSequence;
                        } else if (type == 3) {
                            Sequence<string> *subSequence;
                            subSequence = static_cast<ArraySequence<string>*>(sequence_string->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_string->Get(i) << " ";
                            }
                            delete subSequence;
                        }


                    } else if (da_operation == 7) { // Получить длину массива
                        if (type == 1) {
                            cout << sequence_int->GetLength();
                        } else if (type == 2) {
                            cout << sequence_double->GetLength();
                        } else if (type == 3) {
                            cout << sequence_string->GetLength();
                        }


                    } else if (da_operation == 8) { // Задать элемент по индексу Mutable
                        int index;
                        cout << "Введите индекс: ";
                        cin >> index;
                        if (type == 1) {
                            int element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_int->Set(index, element);
                        } else if (type == 2) {
                            double element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_double->Set(index, element);
                        } else {
                            string element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_string->Set(index, element);
                        }

                    } else if (da_operation == 9) { //Задать элемент по индексу Immutable
                        int index;
                        cout << "Введите индекс: ";
                        cin >> index;
                        if (type == 1) {
                            int element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_int = static_cast<ArraySequence<int> *>(sequence_int->SetImmutable(index,
                                                                                                        element));
                        } else if (type == 2) {
                            double element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_double = static_cast<ArraySequence<double> *>(sequence_double->SetImmutable(index,
                                                                                                                 element));
                        } else {
                            string element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_string = static_cast<ArraySequence<string> *>(sequence_string->SetImmutable(index,
                                                                                                                 element));
                        }


                    } else if (da_operation == 10) { // Добавить элемент в конец массива Mutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int->Append(item);
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double->Append(item);
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string->Append(item);
                        }

                    } else if (da_operation == 11) { // Добавить элемент в конец массива Immutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int = static_cast<ArraySequence<int> *>(sequence_int->AppendImmutable(item));
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double = static_cast<ArraySequence<double> *>(sequence_double->AppendImmutable(
                                    item));
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string = static_cast<ArraySequence<string> *>(sequence_string->AppendImmutable(
                                    item));
                        }

                    } else if (da_operation == 12) { // Добавить элемент в начало массива Mutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int->Prepend(item);
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double->Prepend(item);
                        } else {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string->Prepend(item);
                        }

                    } else if (da_operation == 13) { // Добавить элемент в начало массива Immutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int = static_cast<ArraySequence<int> *>(sequence_int->PrependImmutable(item));
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double = static_cast<ArraySequence<double> *>(sequence_double->PrependImmutable(
                                    item));
                        } else {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string = static_cast<ArraySequence<string> *>(sequence_string->PrependImmutable(
                                    item));
                        }


                    } else if (da_operation == 14) { // Конкатенация двух массивов Mutable
                        int size;
                        cout << "Введите размер массива:";
                        cin >> size;

                        if (type == 1) {
                            int temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_int = new ArraySequence<int>(temp, size);
                            sequence_int = sequence_int->Concat(concat_int);


                        } else if (type == 2) {
                            double temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_double = new ArraySequence<double>(temp, size);
                            sequence_double = sequence_double->Concat(concat_double);

                        } else if (type == 3) {
                            string temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_string = new ArraySequence<string>(temp, size);
                            sequence_string = sequence_string->Concat(concat_string);
                        }

                    } else if (da_operation == 15) { // Конкатенация двух массивов Immutable
                        int size;
                        cout << "Введите размер массива:";
                        cin >> size;

                        if (type == 1) {
                            int temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_int = new ArraySequence<int>(temp, size);
                            sequence_int = static_cast<ArraySequence<int> *>(sequence_int->ConcatImmutable(concat_int));

                        } else if (type == 2) {
                            double temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_double = new ArraySequence<double>(temp, size);
                            sequence_double = static_cast<ArraySequence<double> *>(sequence_double->ConcatImmutable(
                                    concat_double));

                        } else {
                            string temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_string = new ArraySequence<string>(temp, size);
                            sequence_string = static_cast<ArraySequence<string> *>(sequence_string->ConcatImmutable(
                                    concat_string));

                        }


                    } else if (da_operation == 16) { // Вставить элемент по индексу Mutable
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;
                        if (type == 1) {
                            int elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_int->InsertAt(elem, index);
                        } else if (type == 2) {
                            double elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_double->InsertAt(elem, index);
                        } else if (type == 3) {
                            string elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_string->InsertAt(elem, index);
                        }

                    } else if (da_operation == 17) { // Вставить элемент по индексу Immutable
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;
                        if (type == 1) {
                            int elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_int = static_cast<ArraySequence<int> *>(sequence_int->InsertAtImmutable(elem,
                                                                                                             index));
                        } else if (type == 2) {
                            double elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_double = static_cast<ArraySequence<double> *>(sequence_double->InsertAtImmutable(
                                    elem, index));
                        } else {
                            string elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_string = static_cast<ArraySequence<string> *>(sequence_string->InsertAtImmutable(
                                    elem, index));
                        }


                    } else if (da_operation == 18) { // Вывести массив
                        if (type == 1) {
                            sequence_int->Print();
                        } else if (type == 2) {
                            sequence_double->Print();
                        } else if (type == 3) {
                            sequence_string->Print();
                        }
                    } else if (da_operation == 19) { // Выйти
                        break;
                    }

                } else if (choice_struct == 2) {
                    LL_UI();
                    // Переменная для выбора для Связанного списка
                    int ll_operation;
                    ll_operation = input(1, 19);

                    if (ll_operation == 1) {
                        // Копировать элементы из массива

                        cout << "Введите размер массива: ";

                        int size;
                        cin >> size;

                        if (type == 1) {

                            int *temp = new int[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_int = new ListSequence<int>(temp, size);

                            delete[] temp;

                        } else if (type == 2) {

                            double *temp = new double[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_double = new ListSequence<double>(temp, size);

                            delete[] temp;

                        } else {

                            string *temp = new string[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            sequence_string = new ListSequence<string>(temp, size);

                            delete[] temp;
                        }

                    } else if (ll_operation == 2) { // Создать массив заданной длины
                        int size;
                        cout << "Введите длину массива:";
                        cin >> size;

                        if (type == 1) {
                            sequence_int = new ListSequence<int>(size);
                        } else if (type == 2) {
                            sequence_double = new ListSequence<double>(size);
                        } else if (type == 3) {
                            sequence_string = new ListSequence<string>(size);
                        }

                    } else if (ll_operation == 3) { // Получить первый элемент в списке
                        if (type == 1) {
                            cout << sequence_int->GetFirst() << endl;
                        } else if (type == 2) {
                            cout << sequence_double->GetFirst() << endl;
                        } else if (type == 3) {
                            cout << sequence_string->GetFirst() << endl;
                        }

                    } else if (ll_operation == 4) { // Получить последний элемент в списке
                        if (type == 1) {
                            cout << sequence_int->GetLast() << endl;
                        } else if (type == 2) {
                            cout << sequence_double->GetLast() << endl;
                        } else if (type == 3) {
                            cout << sequence_string->GetLast() << endl;
                        }
                    } else if (ll_operation == 5) { // Получить элемент по индексу
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;

                        if (type == 1) {
                            cout << sequence_int->Get(index) << endl;
                        } else if (type == 2) {
                            cout << sequence_double->Get(index) << endl;
                        } else if (type == 3) {
                            cout << sequence_string->Get(index) << endl;
                        }

                    } else if (ll_operation == 6) { // Получить список из элементов
                        int start;
                        int end;
                        cout << "Введите диапазон: ";
                        cin >> start >> end;

                        if (type == 1) {
                            Sequence<int> *subSequence;
                            subSequence = static_cast<ListSequence<int>*>(sequence_int->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_int->Get(i) << " ";
                            }
                            delete subSequence;
                        } else if (type == 2) {
                            Sequence<double> *subSequence;
                            subSequence = static_cast<ListSequence<double>*>(sequence_double->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_double->Get(i) << " ";
                            }
                            delete subSequence;
                        } else if (type == 3) {
                            Sequence<string> *subSequence;
                            subSequence = static_cast<ListSequence<string>*>(sequence_string->GetSubsequence(start, end));
                            for (int i = start; i < end; i++) {
                                cout << sequence_string->Get(i) << " ";
                            }
                            delete subSequence;
                        }

                    } else if (ll_operation == 7) { // Получить длину списка
                        if (type == 1) {
                            cout << sequence_int->GetLength() << endl;
                        } else if (type == 2) {
                            cout << sequence_double->GetLength() << endl;
                        } else if (type == 3) {
                            cout << sequence_string->GetLength() << endl;
                        }

                    } else if (ll_operation == 8) { // Задать элемент по индексу Mutable
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;
                        if (type == 1) {
                            int elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_int->Set(index, elem);
                        } else if (type == 2) {
                            double elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_double->Set(index, elem);
                        } else if (type == 3) {
                            string elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_string->Set(index, elem);
                        }
                    } else if (ll_operation == 9) { //Задать элемент по индексу Immutable
                        int index;
                        cout << "Введите индекс: ";
                        cin >> index;
                        if (type == 1) {
                            int element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_int = static_cast<ListSequence<int> *>(sequence_int->SetImmutable(index, element));
                        } else if (type == 2) {
                            double element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_double = static_cast<ListSequence<double> *>(sequence_double->SetImmutable(index,
                                                                                                                element));
                        } else {
                            string element;
                            cout << "Введите элемент: ";
                            cin >> element;
                            sequence_string = static_cast<ListSequence<string> *>(sequence_string->SetImmutable(index,
                                                                                                                element));
                        }

                    } else if (ll_operation == 10) { // Добавить элемент в конец списка Mutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int->Append(item);
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double->Append(item);
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string->Append(item);
                        }

                    } else if (ll_operation == 11) { // Добавить элемент в конец массива Immutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int = static_cast<ListSequence<int> *>(sequence_int->AppendImmutable(item));
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double = static_cast<ListSequence<double> *>(sequence_double->AppendImmutable(
                                    item));
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string = static_cast<ListSequence<string> *>(sequence_string->AppendImmutable(
                                    item));
                        }


                    } else if (ll_operation == 12) { // Добавить элемент в начало списка Mutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int->Prepend(item);
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double->Prepend(item);
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string->Prepend(item);
                        }

                    } else if (ll_operation == 13) { // Добавить элемент в начало массива Immutable
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int = static_cast<ListSequence<int> *>(sequence_int->PrependImmutable(item));
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double = static_cast<ListSequence<double> *>(sequence_double->PrependImmutable(
                                    item));
                        } else {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string = static_cast<ListSequence<string> *>(sequence_string->PrependImmutable(
                                    item));
                        }

                    } else if (ll_operation == 14) { // Кокатенация Mutable
                        int size;
                        cout << "Введите размер массива:";
                        cin >> size;

                        if (type == 1) {
                            int temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_int = new ListSequence<int>(temp, size);
                            sequence_int = sequence_int->Concat(concat_int);
                        } else if (type == 2) {
                            double temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_double = new ListSequence<double>(temp, size);
                            sequence_double = sequence_double->Concat(concat_double);

                        } else if (type == 3) {
                            string temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_string = new ListSequence<string>(temp, size);
                            sequence_string = sequence_string->Concat(concat_string);
                        }

                    } else if (ll_operation == 15) { // Конкатенация двух массивов Immutable
                        int size;
                        cout << "Введите размер массива:";
                        cin >> size;

                        if (type == 1) {
                            int temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_int = new ListSequence<int>(temp, size);
                            sequence_int = static_cast<ListSequence<int> *>(sequence_int->ConcatImmutable(concat_int));

                        } else if (type == 2) {
                            double temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_double = new ListSequence<double>(temp, size);
                            sequence_double = static_cast<ListSequence<double> *>(sequence_double->ConcatImmutable(
                                    concat_double));

                        } else {
                            string temp[size];

                            cout << "Введите элементы массива: ";
                            for (int i = 0; i < size; i++)
                                cin >> temp[i];

                            concat_string = new ListSequence<string>(temp, size);
                            sequence_string = static_cast<ListSequence<string> *>(sequence_string->ConcatImmutable(
                                    concat_string));

                        }


                    } else if (ll_operation == 16) { // Вставить элемент в заданную позицию Mutable
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;
                        if (type == 1) {
                            int item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_int->InsertAt(item, index);
                        } else if (type == 2) {
                            double item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_double->InsertAt(item, index);
                        } else if (type == 3) {
                            string item;
                            cout << "Введите элемент:";
                            cin >> item;
                            sequence_string->InsertAt(item, index);
                        }

                    } else if (ll_operation == 17) { // Вставить элемент по индексу Immutable
                        int index;
                        cout << "Введите индекс:";
                        cin >> index;
                        if (type == 1) {
                            int elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_int = static_cast<ListSequence<int> *>(sequence_int->InsertAtImmutable(elem,
                                                                                                            index));
                        } else if (type == 2) {
                            double elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_double = static_cast<ListSequence<double> *>(sequence_double->InsertAtImmutable(
                                    elem, index));
                        } else {
                            string elem;
                            cout << "Введите элемент:";
                            cin >> elem;
                            sequence_string = static_cast<ListSequence<string> *>(sequence_string->InsertAtImmutable(
                                    elem, index));
                        }

                    } else if (ll_operation == 18) {
                        if (type == 1) {
                            sequence_int->Print();
                        } else if (type == 2) {
                            sequence_double->Print();
                        } else if (type == 3) {
                            sequence_string->Print();
                        }
                    } else if (ll_operation == 19) { // Выйти
                        break;
                    }


                }
            }
        } else if (choice_type_struct == 3) { // Тесты программы
            while (1) {
                T_UI();
                int tests = input(1, 3);

                if (tests == 1) {
                    TEST_DA();
                } else if (tests == 2) {
                    TEST_LL();

                } else if (tests == 3){
                    break;
                }


            }

        } else if (choice_type_struct == 4) {
            break;
        }

        
    }
}
