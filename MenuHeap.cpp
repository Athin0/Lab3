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
        cout << "��������� ����� ��������� �����������: \n"
             << "\t1: ������ � ��������� ����\n"
             << "\t2: ��������� �������� ��� ������\n"
             << "\t3: ������� ���� � �������\n"
             << "\t4: ������� ��� ����������� ���� � ������\n"
             << "\t5: ��������� ������� ������������ ����\n"
             << "\t6: ��������� ���������� �������\n"
             << "������� �����: ";
        cin >> item;
        if (item < 1 || item > 6) {
            cout << "������! ��� ������ ������! ��������� �������\n";
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

    cout << "������� ����������� ��������� ���� ��� -1 ��� ������\n: ";
    do {
        if (count < 0) {
            cout << "���������� ��������� �� ����� ���� �������������!\n: ";
        }
        cin >> count;

        if (count == -1)
            return;
    } while (count < 0);

    auto item = GetType();
    if (item == 0) return;

    cout << "������������� ���� ������������� ��� ������ �������?:\n"
            "\t0: �����\n"
            "\t1: ������ ���� �������\n"
            "\t2: ������������� ����\n: ";

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

    cout << "������ ������ ��� ���� ����?\n"
            "\t0 - ���\n"
            "\t1 - ��\n: ";

    item = GetInt(0, 1);
    if (item) {
        readHeap(intArr, floatArr);
    }
}

template<class T>
void readTypeHeap(ArraySequence<Heap<T> *> *arr, int count) {
    cout << "������� �������� ����\n:";

    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elements.Append(item);
    }
    Heap<T> heap(elements);
    cout << "�� �����: " << heap
         << "\n�������� ��� ����? (1 - ��, 0 - ��������� ������� �����, "
         << "������ ����� ������� � ������ �� �������)\n:";
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
    cout << "�������������:\n" << heap <<
         "\n�������� ��� ������������� �����?\n"
         "\t-1: �����\n"
         "\t 0: ������������� �����\n"
         "\t 1: �������� ���� � ������\n: ";
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
        cout << "����� ��� ���!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "� ������ ��������� \"" << len <<
             "\" ���, �������:\n"
             "\t- ����� ������ ���� ��� ������\n"
             "\t- ������ ����, ��� ��� ������\n"
             "\t- �����, ������ ��� ����� ���������, ��� ������ ���� ���\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "�� �������: " << *arr->Get(item) << endl;

        cout << "����� �������� ���������� ���������:\n"
                "\t0: ������� ������ ����\n"
                "\t1: �������� �������� � ����\n"
                "\t2: ����� � ������� ������������ ������� �� ����\n"
                "\t3: ��������� �� ��������� �������� � ����\n"
                "\t4: ����������� ����\n: ";

        int item2 = GetInt(0, 4);

        if (item2 == 0) continue;

        auto *Heap1 = arr->Get(item);

        if (item2 == 4) {
            cout << "�������:\n"
                    "\t-1: ��� ������ ������ ����\n"
                    "\t- ������ ���� ��� ���������� ������ ��������\n: ";

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
                    cout << "������� ��������\n: ";
                    cin >>  element;
                    Heap1->Insert( element);
                    cout << "�������� ���� ���������!\n";
                    break;
                case 2:
                    element = Heap1->GetMax();
                    cout << "������������ �������: "<<element<< " ��� ������!\n";
                    break;
                case 3:
                    cout << "������� ��������\n: ";
                    cin >> element;

                    if (Heap1->Find(element))
                        cout << "������ �������� ��������� � ����.\n";
                    else{
                        cout << "������ �������� �� ��������� � ����.\n";}
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
        cout << "����� ��� ���!";
        return;
    }
    int item;
    do {
        cout << "� ������ ��������� \"" << arr->GetLength() <<
             "\" ��� ����� ����, �������:\n"
             "\t- ������ �������� ��� � ������ � �������\n"
             "\t- �����, ������ ��� ���������� ��� ��� ������ ����"
             " ��� ����� ����\n"
             "\t- ����� ������ ���� ��� ������ �� �������\n:";
        item = GetInt();

        if (item < 0) break;

        cout << "� ����� ������� ���������� ������� \"" << item << "\" ����:\n"
                                                                   "\t0: ������� ������ ����\n"
                                                                   "\t1: � ������� ������ ���\n"
                                                                   "\t2: � ���� ������\n: ";

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
        cout << "����� ��� ���!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "������ �� �������� ��� ����� ����! �������������� ����� �� �������\n";
            break;
        }
        cout << "� ������ ��������� \"" << len << "\" ���, �������:\n"
                                                  "\t- ����� ������ ���� ��� ������ �� �������\n"
                                                  "\t- ������ ��������, ��� ��� ������\n"
                                                  "\t- �����, ������ ����� �������, ��� ������ ��� � �������\n: ";

        item = GetInt();

        if (item < 0) break;

        if (item >= arr->GetLength()) {
            printArr(arr);
            continue;
        }

        cout << "�������� ��������:"
                "\t-1: ��������� � ������ �������\n"
                "\t 0: ��� �������� ��������\n"
                "\t 1: ��� ����������� �������� �� ������ �����\n: ";
        int item2 = GetInt(-1, 1);

        if (item2 == -1) continue;

        if (item2 == 0) {
            cout << "�� ������������� ������ ������� \"" << *arr->Get(item) << "\" ?\n"
                                                                               "\t0 - ���\n"
                                                                               "\t1 - ��\n: ";
            item2 = GetInt(0, 1);
            if (item2 == 1) {
                arr->Pop(item);
            }
            continue;
        }

        cout << "������� ����� ����, � ������� ���� �������� \""
             << item << "\" ������\n: ";

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
    cout << "�������:\n"
            "\t- ������������� ����� ��� ����� �������� ������\n"
            "\t- ���� ��� ������������� ����� ��� ������\n: ";
    int count = GetInt();
    if (count <= 0)
        return;

    test(count, 1);

    cout << "������ ��������� ������������ ��� ���?\n"
            "\t0 - ���\n"
            "\t1 - ��\n: ";
    count = GetInt(0, 1);
    if (count == 1)
        testFuncHeap();
}