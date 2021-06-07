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
        cout << "Программа имеет следующие возможности: \n"
             << "\t1: Ввести и запомнить очередь\n"
             << "\t2: Выполнить операцию над очередями\n"
             << "\t3: Вывести очередь в консоль\n"
             << "\t4: Удалить или переместить очереди в памяти\n"
             << "\t5: Запустить функцию тестирования очередей\n"
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

    cout << "Введите колличество элементов очереди или -1 для выхода\n: ";
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

    cout << "Сгенерировать очередь автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести очередь вручную\n"
            "\t2: сгенерировать очередь\n: ";

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

    cout << "Хотите ввести ещё одну очередь?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readQueue(intArr, floatArr);
    }
}

template<class T, class K>
void readTypeQueue(ArraySequence<Queue<T, K> *> *arr, int count) {
    cout << "Введите ключи и элементы очереди\n:";

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
    cout << "Вы ввели: " << Queue0
         << "\nЗаписать это очередь? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
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
    cout << "Сгенерировано:\n" << Queue0 <<
         "\nЗаписать или сгенерировать новое?\n"
         "\t-1: выход\n"
         "\t 0: сгенерировать новое\n"
         "\t 1: записать очередь в память\n: ";
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
        cout << "Таких очередей нет!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "В памяти находится \"" << len <<
             "\" очередей, введите:\n"
             "\t- число меньше нуля для выхода\n"
             "\t- индекс очереди, для её выбора\n"
             "\t- число, больше чем число элементов, для вывода всех очередей\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "Вы выбрали: " << *arr->Get(item) << endl;

        cout << "Какую операцию необходимо выполнить:\n"
                "\t0: выбрать другое очередь\n"
                "\t1: добавить значение в очередь\n"
                "\t2: удалить значение из очереди\n"
                "\t3: проверить на вхождение значения\n"
                "\t4: скопировать очередь\n"
                "\t5: извлечь подочередь\n"
                "\t6: проверить на вхождение подочереди\n: ";

        int item2 = GetInt(0, 6);

        if (item2 == 0) continue;

        auto *Queue1 = arr->Get(item);

        if (item2 == 4 || item2 == 6) {
            cout << "Введите:\n"
                    "\t-1: для выбора другого очереди\n"
                    "\t- индекс очереди для выполнения данной операции\n: ";

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
                        cout << "Данное очередь является подочередью!\n";
                    else
                        cout << "Данное подочередь не было найдено!\n";
                    break;
            }
        } else {
            T element;
            K value;
            switch (item2) {
                default:
                    break;
                case 1:
                    cout << "Введите приоритет\n: ";
                    cin >>  element;
                    cout << "Введите данные\n: ";
                    cin >>  value;
                    Queue1->Insert( element,value);
                    cout << "Значение было добавлено!\n";
                    break;
                case 2:
                    cout << "Введите значение\n: ";
                    cin >> element;
                    Queue1->Remove(element);
                    cout << "Данное значение было удалёно!\n";
                    break;
                case 3:
                    cout << "Введите значение\n: ";
                    cin >> element;

                    if (Queue1->Find(element))
                        cout << "Данное значение находится в Очереди.\n";
                    else{
                        cout << "Данное значение НЕ находится в Очереди.\n";}
                    break;
                case 5:
                    T start, end;
                    cout << "Введите значение начала подпоследовательности\n: ";
                    cin >> start;
                    cout << "Введите значение конца подпоследовательности\n: ";
                    cin >> end;
                    auto *res = Queue1->SubSequence(start,end);
                    cout << "Получено\""  << "\".\n";
                    cout << *res  << "\".\n";
                    arr->Append(res);

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
        cout << "Таких очередей нет!";
        return;
    }
    int item;
    do {
        cout << "В памяти находится \"" << arr->GetLength() <<
             "\" очередей этого типа, введите:\n"
             "\t- Индекс элемента для его вывода в консоль\n"
             "\t- Число, больше чем количество очередей для вывода всех"
             " очередей этого типа\n"
             "\t- Число меньше нуля для выхода из функции\n:";
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
        cout << "Таких очередей нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "Больше не осталось очередей этого типа! Автоматический выход из функции\n";
            break;
        }
        cout << "В памяти находится \"" << len << "\" очередей, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода очередей в консоль\n: ";

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

        cout << "Введите номер очереди, с которым надо поменять \""
             << item << "\" очередь\n: ";

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
    cout << "Введите:\n"
            "\t- положительное число для ввода итераций тестов\n"
            "\t- нуль или отрицательное число для выхода\n: ";
    int count = GetInt();
    if (count <= 0)
        return;

    testQueue(count, 1);

    cout << "Хотите запустить тестирование ещё раз?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";
    count = GetInt(0, 1);
    if (count == 1)
        testFuncQueue();
}
