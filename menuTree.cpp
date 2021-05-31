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

    cout << "������ ������ ��� ���� ������?\n"
            "\t0 - ���\n"
            "\t1 - ��\n: ";

    item = GetInt(0, 1);
    if (item) {
        readBinaryTree(intArr, floatArr);
    }
}

template<class T>
void readTypeBinaryTree(ArraySequence<BinaryTree<T> *> *arr, int count) {
    cout << "������� ����� � �������� ������\n:";
     
    ArraySequence<T> elements;
    for (int i = 0; i < count; i++) {
        T item;
        cin >>  item;
        elements.Append(item);
    }
    BinaryTree<T> binaryTree(elements);
    cout << "�� �����: " << binaryTree
         << "\n�������� ��� ������? (1 - ��, 0 - ��������� ������� �����, "
         << "������ ����� ������� � ������ �� �������)\n:";
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
    cout << "�������������:\n" << binaryTree <<
         "\n�������� ��� ������������� �����?\n"
         "\t-1: �����\n"
         "\t 0: ������������� �����\n"
         "\t 1: �������� ������ � ������\n: ";
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

        auto *BinaryTree1 = arr->Get(item);

        if (item2 == 4 || item2 == 6) {
            cout << "�������:\n"
                    "\t-1: ��� ������ ������� ������\n"
                    "\t- ������ ������ ��� ���������� ������ ��������\n: ";

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
                        cout << "������ ������ �������� ����������!\n";
                    else
                        cout << "������ ��������� �� ���� �������!\n";
                    break;
            }
        } else {
            T element;

            switch (item2) {
                default:
                    break;
                case 1:
                    cout << "������� ��������\n: ";
                    cin >>  element;
                    BinaryTree1->Insert( element);
                    cout << "�������� ���� ���������!\n";
                    break;
                case 2:
                    cout << "������� ��������\n: ";
                    cin >> element;
                    BinaryTree1->Remove(element);
                    cout << "������ �������� ���� ������!\n";
                    break;
                case 3:
                    cout << "������� ��������\n: ";
                    cin >> element;

                    if (BinaryTree1->Find(element))
                        cout << "������ �������� ��������� � ������.\n";
                    else{
                        cout << "������ �������� �� ��������� � ������.\n";}
                    break;
                case 5:
                    cout << "������� ��������\n: ";
                    cin >> element;
                    auto *res = BinaryTree1->SubTree(element);
                    cout << "�� �������� \"" << element << "\" ��������\"" << res->GetStrGreatTree() << "\".\n";
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

        cout << "� ����� ������� ���������� ������� \"" << item << "\" ������:\n"
                                                                   "\t0: ������� ������ ������\n"
                                                                   "\t1: � ������� ������������ ������\n"
                                                                   "\t2: � ���� ������\n: ";

        int item1 = GetInt(0, 2);

        if (item1 == 0)
            continue;

        if (item1 == 2) {
            cout << *arr->Get(item) << endl;
            continue;
        }
        while (true) {
            cout << "� ����� ������� ���������� ������� ������:\n"
                    "\t1: ����\n"
                    "\t2: ������\n"
                    "\t3: �����\n: "
                    "\t0: �����\n: ";
            int First, Second, Third;
            if((First = GetInt(0, 3)) == 0)
                break;
             Second = GetInt(1, 3);
             Third = GetInt(1, 3);

            if (First + Second + Third != 6 && First != Second) {
                cout << "����������!\n";
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
            BinaryTree<T> *BinaryTree = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(BinaryTree, item2);
        }
    }
}

//5
void testFuncBinaryTree() {
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
        testFuncBinaryTree();
}