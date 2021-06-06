//
// Created by arina on 06.06.2021.
//
#include "menuQueue.h"
#include "Queue.h"
#include "iostream"
#include "DynamicArraySequence.h"
#include "baseFunc.h"
#include "Test.h"

using namespace std;

template<class T, class K>
void printArr(ArraySequence<Queue<T, K> *> *arr) {
    for (int i = 0; i < arr->GetLength(); i++) {
        cout << i << ": " << *arr->Get(i) << endl;
    }
    cout << endl;
}

void mainMenuQueue() {
    ArraySequence<Queue<int,int> *> arrInt;
    ArraySequence<Queue<float, float> *> arrFloat;
    int item;
    while (true) {
        cout << "��������� ����� ��������� �����������: \n"
             << "\t1: ������ � ��������� ������\n"
             << "\t2: ��������� �������� ��� ���������\n"
             << "\t3: ������� ������ � �������\n"
             << "\t4: ������� ��� ����������� ������� � ������\n"
             << "\t5: ��������� ������� ������������ ��������\n"
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
                readQueue(&arrInt, &arrFloat);
                break;
            case 2:
                operationWithQueue(&arrInt, &arrFloat);
                break;
            case 3:
                printQueue(&arrInt, &arrFloat);
                break;
            case 4:
                deleteQueue(&arrInt, &arrFloat);
                break;
            case 5:
                testFuncQueue();
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
void readQueue(ArraySequence<Queue<int,int> *> *intArr,
                    ArraySequence<Queue<float, float> *> *floatArr) {

    int count = 0;

    cout << "������� ����������� ��������� ������ ��� -1 ��� ������\n: ";
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

    cout << "������������� ������ ������������� ��� ������ �������?:\n"
            "\t0: �����\n"
            "\t1: ������ ������ �������\n"
            "\t2: ������������� ������\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeQueue<int>(intArr, count);
                break;
            case 2:
                readTypeQueue<float>(floatArr, count);
                break;
            default:
                break;
        }
    }

    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomQueue<int,int>(intArr, count, randomInt);
                break;
            case 2:
                generateRandomQueue<float,float>(floatArr, count, randomFloat);
                break;
            default:
                break;
        }
    }

    cout << "������ ������ ��� ���� ������?\n"
            "\t0 - ���\n"
            "\t1 - ��\n: ";

    item = GetInt(0, 1);
    if (item) {
        readQueue(intArr, floatArr);
    }
}

template<class T, class K>
void readTypeQueue(ArraySequence<Queue<T, K> *> *arr, int count) {
    cout << "������� ����� � �������� ������\n:";

    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elements.Append(item);
    }
    ArraySequence<T> elementsVal;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elementsVal.Append(item);
    }
    Queue<T, K> Queue0(elements,elementsVal);
    cout << "�� �����: " << Queue0
         << "\n�������� ��� ������? (1 - ��, 0 - ��������� ������� �����, "
         << "������ ����� ������� � ������ �� �������)\n:";
    int item;
    cin >> item;

    switch (item) {
        default:
            break;
        case 0:
            readTypeQueue<T>(arr, count);
            break;
        case 1:
            arr->Append(new Queue<T, K>(elements,elementsVal));
            break;
    }
}

template<class T, class K>
void generateRandomQueue(ArraySequence<Queue<T, K> *> *arr, int count, T (*funcT)()) {

    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        elements.Append(funcT());
    }
    ArraySequence<T> elementsVal;
    for (int i = 0; i < count; i++) {
        elementsVal.Append(funcT());
    }
    Queue<T, K> Queue0(elements, elementsVal);
    cout << "�������������:\n" << Queue0 <<
         "\n�������� ��� ������������� �����?\n"
         "\t-1: �����\n"
         "\t 0: ������������� �����\n"
         "\t 1: �������� ������ � ������\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomQueue(arr, count,  funcT);
            break;
        case 1:
            auto *res = new Queue<T,K>(elements,elementsVal);
            arr->Append(res);
            break;
    }
}

//2
void operationWithQueue(ArraySequence<Queue<int,int> *> *intArr,
                             ArraySequence<Queue<float, float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            operationTypeWithQueue<int>(intArr);
            break;
        case 2:
            operationTypeWithQueue<float>(floatArr);
            break;
    }
}

template<class T, class K>
void operationTypeWithQueue(ArraySequence<Queue<T, K> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "����� �������� ���!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "� ������ ��������� \"" << len <<
             "\" ��������, �������:\n"
             "\t- ����� ������ ���� ��� ������\n"
             "\t- ������ ������, ��� ��� ������\n"
             "\t- �����, ������ ��� ����� ���������, ��� ������ ���� ��������\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "�� �������: " << *arr->Get(item) << endl;

        cout << "����� �������� ���������� ���������:\n"
                "\t0: ������� ������ ������\n"
                "\t1: �������� �������� � ������\n"
                "\t2: ������� �������� �� ������\n"
                "\t3: ��������� �� ��������� ��������\n"
                "\t4: ����������� ������\n"
                "\t5: ������� ���������\n"
                "\t6: ��������� �� ��������� ���������\n: ";

        int item2 = GetInt(0, 6);

        if (item2 == 0) continue;

        auto *Queue1 = arr->Get(item);

        if (item2 == 4 || item2 == 6) {
            cout << "�������:\n"
                    "\t-1: ��� ������ ������� ������\n"
                    "\t- ������ ������ ��� ���������� ������ ��������\n: ";

            int item3 = GetInt(-1, len - 1);
            if (item3 == -1) {
                continue;
            }

            Queue<T, K> *Queue2, *Queue3;

            switch (item2) {
                default:
                    break;
                case 4:
                    Queue3 = new Queue<T, K>(*Queue1);
                    arr->Append(Queue3);
                    break;
                case 6:
                    Queue2 = arr->Get(item3);
                    bool res = Queue1->FindSubSequence(*Queue2);
                    if (res)
                        cout << "������ ������ �������� ����������!\n";
                    else
                        cout << "������ ��������� �� ���� �������!\n";
                    break;
            }
        } else {
            T element;
            K value;
            switch (item2) {
                default:
                    break;
                case 1:
                    cout << "������� ���������\n: ";
                    cin >>  element;
                    cout << "������� ������\n: ";
                    cin >>  value;
                    Queue1->Insert( element,value);
                    cout << "�������� ���� ���������!\n";
                    break;
                case 2:
                    cout << "������� ��������\n: ";
                    cin >> element;
                    Queue1->Remove(element);
                    cout << "������ �������� ���� ������!\n";
                    break;
                case 3:
                    cout << "������� ��������\n: ";
                    cin >> element;

                    if (Queue1->Find(element))
                        cout << "������ �������� ��������� � ������.\n";
                    else{
                        cout << "������ �������� �� ��������� � ������.\n";}
                    break;
                case 5:/*
                    cout << "������� ��������\n: ";
                    cin >> element;
                    auto *res = Queue1->FindSubSequence(element);               //TODO  ������� FindSubSequence
                    cout << "�� �������� \"" << element << "\" ��������\""  << "\".\n";
                    arr->Append(res);
                    */
                    break;

            }
        }
    }
}

//3
void printQueue(ArraySequence<Queue<int,int> *> *intArr,
                     ArraySequence<Queue<float, float> *> *floatArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            printTypeQueue<int>(intArr);
            break;
        case 2:
            printTypeQueue<float>(floatArr);
            break;
    }
}


template<class T, class K>
void printTypeQueue(ArraySequence<Queue<T, K> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "����� �������� ���!";
        return;
    }
    int item;
    do {
        cout << "� ������ ��������� \"" << arr->GetLength() <<
             "\" �������� ����� ����, �������:\n"
             "\t- ������ �������� ��� ��� ������ � �������\n"
             "\t- �����, ������ ��� ���������� �������� ��� ������ ����"
             " �������� ����� ����\n"
             "\t- ����� ������ ���� ��� ������ �� �������\n:";
        item = GetInt();

        if (item < 0) break;
        if (item >= arr->GetLength()) {
            printArr(arr);
            continue;
        }
        cout << *arr->Get(item) << endl;



    } while (item >= 0);
}

//4
void deleteQueue(ArraySequence<Queue<int,int> *> *intArr,
                      ArraySequence<Queue<float, float> *> *floatArr) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeQueue(intArr);
            break;
        case 2:
            deleteTypeQueue(floatArr);
            break;
        default:
            break;
    }
}

template<class T, class K>
void deleteTypeQueue(ArraySequence<Queue<T, K> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "����� �������� ���!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "������ �� �������� �������� ����� ����! �������������� ����� �� �������\n";
            break;
        }
        cout << "� ������ ��������� \"" << len << "\" ��������, �������:\n"
                                                  "\t- ����� ������ ���� ��� ������ �� �������\n"
                                                  "\t- ������ ��������, ��� ��� ������\n"
                                                  "\t- �����, ������ ����� �������, ��� ������ �������� � �������\n: ";

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

        cout << "������� ����� ������, � ������� ���� �������� \""
             << item << "\" ������\n: ";

        item2 = GetInt(0, len - 1);
        if (item != item2) {
            Queue<T, K> *Queue0 = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(Queue0, item2);
        }
    }
}

//5
void testFuncQueue() {
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
        testFuncQueue();
}
