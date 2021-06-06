//
// Created by arina on 01.06.2021.
//

#include "MenuHeap.h"
#include "iostream"
#include "Heap.h"
#include "DynamicArraySequence.h"
#include "baseFunc.h"
#include "Test.h"

using namespace std;

template<class T>
void printArr(ArraySequence<Heap<T> *> *arr) {
    for (int i = 0; i < arr->GetLength(); i++) {
        cout << i << ": " << *arr->Get(i) << endl;
    }
    cout << endl;
}

void mainMenuHeap() {
    ArraySequence<Heap<int> *> arrInt;
    ArraySequence<Heap<float> *> arrFloat;
    int item;
    while (true) {
        cout << "Программа имеет следующие возможности: \n"
             << "\t1: Ввести и запомнить кучу\n"
             << "\t2: Выполнить операцию над кучами\n"
             << "\t3: Вывести чучу в консоль\n"
             << "\t4: Удалить или переместить кучи в памяти\n"
             << "\t5: Запустить функцию тестирования кучи\n"
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
                readHeap(&arrInt, &arrFloat);
                break;
            case 2:
                operationWithHeap(&arrInt, &arrFloat);
                break;
            case 3:
                printHeap(&arrInt, &arrFloat);
                break;
            case 4:
                deleteHeap(&arrInt, &arrFloat);
                break;
            case 5:
                testFuncHeap();
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
void readHeap(ArraySequence<Heap<int> *> *intArr,
                    ArraySequence<Heap<float> *> *floatArr) {

    int count = 0;

    cout << "Введите колличество элементов кучи или -1 для выхода\n: ";
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

    cout << "Сгенерировать кучу автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести кучу вручную\n"
            "\t2: сгенерировать кучу\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeHeap<int>(intArr, count);
                break;
            case 2:
                readTypeHeap<float>(floatArr, count);
                break;
            default:
                break;
        }
    }

    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomHeap<int>(intArr, count, randomInt);
                break;
            case 2:
                generateRandomHeap<float>(floatArr, count, randomFloat);
                break;
            default:
                break;
        }
    }

    cout << "Хотите ввести ещё одну кучу?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readHeap(intArr, floatArr);
    }
}

template<class T>
void readTypeHeap(ArraySequence<Heap<T> *> *arr, int count) {
    cout << "Введите элементы кучи\n:";

    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elements.Append(item);
    }
    Heap<T> heap(elements);
    cout << "Вы ввели: " << heap
         << "\nЗаписать эту кучу? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    cin >> item;

    switch (item) {
        default:
            break;
        case 0:
            readTypeHeap<T>(arr, count);
            break;
        case 1:
            arr->Append(new Heap<T>(elements));
            break;
    }
}

template<class T>
void generateRandomHeap(ArraySequence<Heap<T> *> *arr, int count, T (*funcT)()) {

    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        elements.Append(funcT());
    }
    Heap<T> heap(elements);
    cout << "Сгенерировано:\n" << heap <<
         "\nЗаписать или сгенерировать новую?\n"
         "\t-1: выход\n"
         "\t 0: сгенерировать новое\n"
         "\t 1: записать кучу в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomHeap(arr, count,  funcT);
            break;
        case 1:
            auto *res = new Heap<T>(elements);
            arr->Append(res);
            break;
    }
}

//2
void operationWithHeap(ArraySequence<Heap<int> *> *intArr,
                             ArraySequence<Heap<float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            operationTypeWithHeap<int>(intArr);
            break;
        case 2:
            operationTypeWithHeap<float>(floatArr);
            break;
    }
}

template<class T>
void operationTypeWithHeap(ArraySequence<Heap<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких куч нет!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "В памяти находится \"" << len <<
             "\" куч, введите:\n"
             "\t- число меньше нуля для выхода\n"
             "\t- индекс кучи, для его выбора\n"
             "\t- число, больше чем число элементов, для вывода всех куч\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "Вы выбрали: " << *arr->Get(item) << endl;

        cout << "Какую операцию необходимо выполнить:\n"
                "\t0: выбрать другую кучу\n"
                "\t1: добавить значение в кучу\n"
                "\t2: найти и удалить максимальный элемент из кучи\n"
                "\t3: проверить на вхождение значения в кучу\n"
                "\t4: скопировать кучу\n: ";

        int item2 = GetInt(0, 4);

        if (item2 == 0) continue;

        auto *Heap1 = arr->Get(item);

        if (item2 == 4) {
            cout << "Введите:\n"
                    "\t-1: для выбора другой кучи\n"
                    "\t- индекс кучи для выполнения данной операции\n: ";

            int item3 = GetInt(-1, len - 1);
            if (item3 == -1) {
                continue;
            }

            Heap<T> *Heap2, *Heap3;

            Heap3 = new Heap<T>(*Heap1);
            arr->Append(Heap3);
        } else {
            T element;

            switch (item2) {
                default:
                    break;
                case 1:
                    cout << "Введите значение\n: ";
                    cin >>  element;
                    Heap1->Insert( element);
                    cout << "Значение было добавлено!\n";
                    break;
                case 2:
                    element = Heap1->GetMax();
                    cout << "Максимальный элемент: "<<element<< " был удален!\n";
                    break;
                case 3:
                    cout << "Введите значение\n: ";
                    cin >> element;

                    if (Heap1->Find(element))
                        cout << "Данное значение находится в куче.\n";
                    else{
                        cout << "Данное значение НЕ находится в куче.\n";}
                    break;
            }
        }
    }
}

//3
void printHeap(ArraySequence<Heap<int> *> *intArr,
                     ArraySequence<Heap<float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            printTypeHeap<int>(intArr);
            break;
        case 2:
            printTypeHeap<float>(floatArr);
            break;
    }
}


template<class T>
void printTypeHeap(ArraySequence<Heap<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких куч нет!";
        return;
    }
    int item;
    do {
        cout << "В памяти находится \"" << arr->GetLength() <<
             "\" куч этого типа, введите:\n"
             "\t- Индекс элемента для её вывода в консоль\n"
             "\t- Число, больше чем количество куч для вывода всех"
             " куч этого типа\n"
             "\t- Число меньше нуля для выхода из функции\n:";
        item = GetInt();

        if (item < 0) break;

        cout << "В каком формате необходимо вывести \"" << item << "\" кучу:\n"
                                                                   "\t0: выбрать другую кучу\n"
                                                                   "\t1: в формате списка пар\n"
                                                                   "\t2: в виде дерева\n: ";

        int item1 = GetInt(0, 2);

        if (item1 == 0)
            continue;

        if (item1 == 2) {
            cout << *arr->Get(item) << endl;
            continue;
        }
        cout<< (arr->Get(item))->ListOfPairs() << endl;


    } while (item >= 0);
}

//4
void deleteHeap(ArraySequence<Heap<int> *> *intArr,
                      ArraySequence<Heap<float> *> *floatArr) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeHeap(intArr);
            break;
        case 2:
            deleteTypeHeap(floatArr);
            break;
        default:
            break;
    }
}

template<class T>
void deleteTypeHeap(ArraySequence<Heap<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких куч нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "Больше не осталось куч этого типа! Автоматический выход из функции\n";
            break;
        }
        cout << "В памяти находится \"" << len << "\" куч, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода куч в консоль\n: ";

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

        cout << "Введите номер кучи, с которым надо поменять \""
             << item << "\" дерево\n: ";

        item2 = GetInt(0, len - 1);
        if (item != item2) {
            Heap<T> *Heap = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(Heap, item2);
        }
    }
}

//5
void testFuncHeap() {
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
        testFuncHeap();
}