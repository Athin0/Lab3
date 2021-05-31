//
// Created by arina on 31.05.2021.
//

#include "menuTree.h"
#include "iostream"
#include "BinaryTree.h"
#include "DynamicArraySequence.h"
#include "baseFunc.h"
#include "Test.h"

using namespace std;

template<class T>
void printArr(ArraySequence<BinaryTree<T> *> *arr) {
    for (int i = 0; i < arr->GetLength(); i++) {
        cout << i << ": " << *arr->Get(i) << endl;
    }
    cout << endl;
}

void mainMenuBinaryTree() {
    ArraySequence<BinaryTree<int> *> arrInt;
    ArraySequence<BinaryTree<float> *> arrFloat;
    int item;
    while (true) {
        cout << "Программа имеет следующие возможности: \n"
             << "\t1: Ввести и запомнить дерево\n"
             << "\t2: Выполнить операцию над деревьями\n"
             << "\t3: Вывести дерево в консоль\n"
             << "\t4: Удалить или переместить деревья в памяти\n"
             << "\t5: Запустить функцию тестирования деревьев\n"
             << "\t6: Закончить выполнение функции\n"
             << "Введите число: ";
        cin >> item;
        if (item < 1 || item > 6) {
            cout << "Ошибка! Нет такого пункта! Повторите попытку\n";
            continue;
        }

        if (item == 6)
            break;

        switch (item) {
            case 1:
                readBinaryTree(&arrInt, &arrFloat);
                break;
            case 2:
                operationWithBinaryTree(&arrInt, &arrFloat);
                break;
            case 3:
                printBinaryTree(&arrInt, &arrFloat);
                break;
            case 4:
                deleteBinaryTree(&arrInt, &arrFloat);
                break;
            case 5:
                testFuncBinaryTree();
                break;
            default:
                break;
        }
    }

    for (auto i = 0; i < arrInt.GetLength(); i++) {
        delete arrInt[i];
    }

    for (auto i = 0; i < arrFloat.GetLength(); i++) {
        delete arrFloat[i];
    }
}

//1
void readBinaryTree(ArraySequence<BinaryTree<int> *> *intArr,
                    ArraySequence<BinaryTree<float> *> *floatArr) {

    int count = 0;

    cout << "Введите колличество элементов дерева или -1 для выхода\n: ";
    do {
        if (count < 0) {
            cout << "Количество элементов не может быть отрицательным!\n: ";
        }
        cin >> count;

        if (count == -1)
            return;
    } while (count < 0);

    auto item = GetType();
    if (item == 0) return;

    cout << "Сгенерировать дерево автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести дерево вручную\n"
            "\t2: сгенерировать дерево\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeBinaryTree<int>(intArr, count);
                break;
            case 2:
                readTypeBinaryTree<float>(floatArr, count);
                break;
            default:
                break;
        }
    }

    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomBinaryTree<int>(intArr, count, randomInt);
                break;
            case 2:
                generateRandomBinaryTree<float>(floatArr, count, randomFloat);
                break;
            default:
                break;
        }
    }

    cout << "Хотите ввести ещё одно дерево?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readBinaryTree(intArr, floatArr);
    }
}

template<class T>
void readTypeBinaryTree(ArraySequence<BinaryTree<T> *> *arr, int count) {
    cout << "Введите ключи и элементы дерева\n:";
     
    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elements.Append(item);
    }
    BinaryTree<T> binaryTree(elements);
    cout << "Вы ввели: " << binaryTree
         << "\nЗаписать это дерево? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    cin >> item;

    switch (item) {
        default:
            break;
        case 0:
            readTypeBinaryTree<T>(arr, count);
            break;
        case 1:
            arr->Append(new BinaryTree<T>(elements));
            break;
    }
}

template<class T>
void generateRandomBinaryTree(ArraySequence<BinaryTree<T> *> *arr, int count, T (*funcT)()) {
     
    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        elements.Append(funcT());
    }
    BinaryTree<T> binaryTree(elements);
    cout << "Сгенерировано:\n" << binaryTree <<
         "\nЗаписать или сгенерировать новое?\n"
         "\t-1: выход\n"
         "\t 0: сгенерировать новое\n"
         "\t 1: записать дерево в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomBinaryTree(arr, count,  funcT);
            break;
        case 1:
            auto *res = new BinaryTree<T>(elements);
            arr->Append(res);
            break;
    }
}

//2
void operationWithBinaryTree(ArraySequence<BinaryTree<int> *> *intArr,
                             ArraySequence<BinaryTree<float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            operationTypeWithBinaryTree<int>(intArr);
            break;
        case 2:
            operationTypeWithBinaryTree<float>(floatArr);
            break;
    }
}

template<class T>
void operationTypeWithBinaryTree(ArraySequence<BinaryTree<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких деревьев нет!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "В памяти находится \"" << len <<
             "\" деревьев, введите:\n"
             "\t- число меньше нуля для выхода\n"
             "\t- индекс дерева, для его выбора\n"
             "\t- число, больше чем число элементов, для вывода всем деревьев\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "Вы выбрали: " << *arr->Get(item) << endl;

        cout << "Какую операцию необходимо выполнить:\n"
                "\t0: выбрать другое дерево\n"
                "\t1: добавить значение в дерево\n"
                "\t2: удалить значение из дерева\n"
                "\t3: проверить на вхождение значения\n"
                "\t4: скопировать дерево\n"
                "\t5: извлечь поддерева\n"
                "\t6: проверить на вхождение поддерева\n: ";

        int item2 = GetInt(0, 6);

        if (item2 == 0) continue;

        auto *BinaryTree1 = arr->Get(item);

        if (item2 == 4 || item2 == 6) {
            cout << "Введите:\n"
                    "\t-1: для выбора другого дерева\n"
                    "\t- индекс дерева для выполнения данной операции\n: ";

            int item3 = GetInt(-1, len - 1);
            if (item3 == -1) {
                continue;
            }

            BinaryTree<T> *BinaryTree2, *BinaryTree3;

            switch (item2) {
                default:
                    break;
                case 4:
                    BinaryTree3 = new BinaryTree<T>(*BinaryTree1);
                    arr->Append(BinaryTree3);
                    break;
                case 6:
                    BinaryTree2 = arr->Get(item3);
                    bool res = BinaryTree1->FindSubTree(*BinaryTree2);
                    if (res)
                        cout << "Данное дерево является поддеревом!\n";
                    else
                        cout << "Данное поддерево не было найдено!\n";
                    break;
            }
        } else {
            T element;

            switch (item2) {
                default:
                    break;
                case 1:
                    cout << "Введите значение\n: ";
                    cin >>  element;
                    BinaryTree1->Insert( element);
                    cout << "Значение было добавлено!\n";
                    break;
                case 2:
                    cout << "Введите значение\n: ";
                    cin >> element;
                    BinaryTree1->Remove(element);
                    cout << "Данное значение было удалёно!\n";
                    break;
                case 3:
                    cout << "Введите значение\n: ";
                    cin >> element;

                    if (BinaryTree1->Find(element))
                        cout << "Данное значение находится в Дереве.\n";
                    else{
                        cout << "Данное значение НЕ находится в Дереве.\n";}
                    break;
                case 5:
                    cout << "Введите значение\n: ";
                    cin >> element;
                    auto *res = BinaryTree1->SubTree(element);
                    cout << "По значению \"" << element << "\" получено\"" << res->GetStrGreatTree() << "\".\n";
                    arr->Append(res);
                    break;

            }
        }
    }
}

//3
void printBinaryTree(ArraySequence<BinaryTree<int> *> *intArr,
                     ArraySequence<BinaryTree<float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            printTypeBinaryTree<int>(intArr);
            break;
        case 2:
            printTypeBinaryTree<float>(floatArr);
            break;
    }
}


template<class T>
void printTypeBinaryTree(ArraySequence<BinaryTree<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких деревьев нет!";
        return;
    }
    int item;
    do {
        cout << "В памяти находится \"" << arr->GetLength() <<
             "\" деревьев этого типа, введите:\n"
             "\t- Индекс элемента для его вывода в консоль\n"
             "\t- Число, больше чем количество деревьев для вывода всех"
             " деревьев этого типа\n"
             "\t- Число меньше нуля для выхода из функции\n:";
        item = GetInt();

        if (item < 0) break;

        cout << "В каком формате необходимо вывести \"" << item << "\" дерево:\n"
                                                                   "\t0: выбрать другое дерево\n"
                                                                   "\t1: в формате произвольной строки\n"
                                                                   "\t2: в виде дерева\n: ";

        int item1 = GetInt(0, 2);

        if (item1 == 0)
            continue;

        if (item1 == 2) {
            cout << *arr->Get(item) << endl;
            continue;
        }
        while (true) {
            cout << "В каком формате необходимо вывести дерево:\n"
                    "\t1: лево\n"
                    "\t2: корень\n"
                    "\t3: право\n: "
                    "\t0: Выход\n: ";
            int First, Second, Third;
            if((First = GetInt(0, 3)) == 0)
                break;
             Second = GetInt(1, 3);
             Third = GetInt(1, 3);

            if (First + Second + Third != 6 && First != Second) {
                cout << "НЕВОЗМОЖНО!\n";
                continue;
            }
            cout << arr->Get(item)->In_Str(First,Second,Third) << endl;
            break;
        }


    } while (item >= 0);
}

//4
void deleteBinaryTree(ArraySequence<BinaryTree<int> *> *intArr,
                      ArraySequence<BinaryTree<float> *> *floatArr) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeBinaryTree(intArr);
            break;
        case 2:
            deleteTypeBinaryTree(floatArr);
            break;
        default:
            break;
    }
}

template<class T>
void deleteTypeBinaryTree(ArraySequence<BinaryTree<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких деревьев нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "Больше не осталось деревьев этого типа! Автоматический выход из функции\n";
            break;
        }
        cout << "В памяти находится \"" << len << "\" деревьев, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода деревьев в консоль\n: ";

        item = GetInt();

        if (item < 0) break;

        if (item >= arr->GetLength()) {
            printArr(arr);
            continue;
        }

        cout << "Выберите операцию:"
                "\t-1: вернуться к выбору индекса\n"
                "\t 0: для удаления элемента\n"
                "\t 1: для перемещения элемента на другое место\n: ";
        int item2 = GetInt(-1, 1);

        if (item2 == -1) continue;

        if (item2 == 0) {
            cout << "Вы действительно хотите удалить \"" << *arr->Get(item) << "\" ?\n"
                                                                               "\t0 - нет\n"
                                                                               "\t1 - да\n: ";
            item2 = GetInt(0, 1);
            if (item2 == 1) {
                arr->Pop(item);
            }
            continue;
        }

        cout << "Введите номер дерева, с которым надо поменять \""
             << item << "\" дерево\n: ";

        item2 = GetInt(0, len - 1);
        if (item != item2) {
            BinaryTree<T> *BinaryTree = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(BinaryTree, item2);
        }
    }
}

//5
void testFuncBinaryTree() {
    cout << "Введите:\n"
            "\t- положительное число для ввода итераций тестов\n"
            "\t- нуль или отрицательное число для выхода\n: ";
    int count = GetInt();
    if (count <= 0)
        return;

   test(count, 1);

    cout << "Хотите запустить тестирование ещё раз?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";
    count = GetInt(0, 1);
    if (count == 1)
        testFuncBinaryTree();
}