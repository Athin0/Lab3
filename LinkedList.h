//
// Created by arina on 09.04.2021.
//

#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H
#include "iostream"
#include "cstdlib"
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
public:
    typedef struct Element {        //структура одного элемента связного списка
        T data;                     // * данные, хранящиеся в одном элементе
        struct Element *next;       // * ссылка на следующий элемент
    } element;
private:
    int len = 0;                    //длина связного списка

    element *head = nullptr;        //ссылка на начало списка
    element *ending = nullptr;      //ссылка на конец списка
public:
    class IndexOutOfRange {
    public:
        int length;
        int index;

        IndexOutOfRange(int length, int index) : length(length), index(index) {};

        IndexOutOfRange() : length(-1), index(-1) {};
    };


    LinkedList(T *items, int count);     //Копировать элементы из переданного массива

    LinkedList();                        //Создать пустой список

    LinkedList(const LinkedList<T> &linkedList1); //Копирующий конструктор

    ~LinkedList();


    void Append(T item);

    void Prepend(T item);

    void Insert(T item, int index);

    void Set(T index, int item);

    T GetFirst();

    T GetLast();

    int GetLength() const;

    T Get(int index) const;

    T &operator[](int ind);

    LinkedList<T> *GetSubList(int startIndex, int endIndex); //TODO возращаемый тип *

    LinkedList<T> *Concat(LinkedList<T> *list);

    void operator = (LinkedList<T> linkedList) {
        element *el = linkedList.head;
        while(el != nullptr) {
            Append(el->data);
            el = el->next;
        }
    }

    void operator = (LinkedList<T> *linkedList);
    void Delete();

    friend std::ostream &operator<<(std::ostream &cout, LinkedList<T> linkedList) { //TODO убрать из класса
        element *el = linkedList.head;
        cout << '{';
        while (el != nullptr) {
            cout << el->data;
            if (el->next)
                cout << ", ";
            el = el->next;
        }
        cout << '}';
        return cout;
    }


};


template<class T>
void LinkedList<T>::Append(T item) {  //добавление элемента в конец списка
    auto *el = new element;             //создание элемента с входными данными
    el->data = item;
    el->next = nullptr;
    len++;
    if (head == nullptr) {              //проверка на пустоту списка
        head = el;
        ending = el;
        return;
    }
    ending->next = el;                     //добавление элемента в конец
    ending = el;
}

template<class T>
void LinkedList<T>::Prepend(T item) { //добавление в начало
    auto *el = new element;             //создание нового элемента и заполнение
    el->data = item;
    el->next = head;
    len++;
    if (head == nullptr) {
        head = el;
        ending = el;
        return;
    }
    head = el;
}

template<class T>
void LinkedList<T>::Insert(T item, int index) {
    if (index < 0 || index >= len)
        throw IndexOutOfRange(len, index);
    if (index == 0) {
        Prepend(item);
    } else {
        element *el = head;
        for (int i = 0; i < index - 1; i++)
            el = el->next;

        element *elNew = new element;
        elNew->data = item;
        elNew->next = el->next;
        el->next = elNew;
        len++;
    }
}

template<class T>
//задает значение какому либо элементу
void LinkedList<T>::Set(T index, int item) {
    if (index < 0 || index >= len)
        throw IndexOutOfRange(len, index);
    element *el = head;
    for (int i = 0; i < index; i++, el = el->next);
    el->data = item;
}

template<class T>
LinkedList<T>::LinkedList() {
    len = 0;
    head = nullptr;
    ending = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(T *items, int count) {
    if (count < 0)
        throw IndexOutOfRange(0, count);
    for (int i = 0; i < count; i++) {
        Append(items[i]);
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &linkedList1) {
    element *el = linkedList1.head;
    while (el != nullptr) {
        Append(el->data);
        el = el->next;
    }
}

template<class T>
T LinkedList<T>::GetFirst() {
    if (head == nullptr)
        throw IndexOutOfRange(len, 0); //обработка ошибки
    return head->data;
}

template<class T>
T LinkedList<T>::GetLast() {
    if (ending == nullptr)
        throw IndexOutOfRange(len, len - 1); //обработка ошибки

    return ending->data;
}

template<class T>
T LinkedList<T>::Get(int index) const {
    if (index < 0 || index >= len)
        throw IndexOutOfRange();
    element *el = head;
    for (int i = 0; i < index; i++)
        el = el->next;
    return el->data;
}

template<class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex < 0 || startIndex > len)
        throw IndexOutOfRange(len, startIndex);
    if (endIndex < 0 || endIndex > len)
        throw IndexOutOfRange(len, endIndex);

    LinkedList<T> *newLinkedList = new LinkedList<T>;
    for (int i = startIndex; i < endIndex; i++) {
        newLinkedList->Append(Get(i));
    }
    return newLinkedList;
}

template<class T>
int LinkedList<T>::GetLength() const {
    return len;
}


template<class T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) {
    for (int i = 0; i < list->GetLength(); i++) {
        Append((*list)[i]);
    }
    return this;
};

template<class T>
LinkedList<T>::~LinkedList() {
    Element *el = head;
    while (el != nullptr) {
        head = el;
        el = head->next;
        delete head;
    }
}

template<class T>
T &LinkedList<T>::operator[](int index) {
    if (index >= len || index < 0) throw IndexOutOfRange();

    element *el = head;
    for (int i = 0; i < index; i++)
        el = el->next;
    return el->data;
}


template<class T>
void LinkedList<T>::operator=(LinkedList<T> *linkedList) {
    Delete();
    head = linkedList->head;
    ending = linkedList->ending;
    len = linkedList->len;
}
template <class T>
void LinkedList<T>:: Delete() {
    Element *next = head;
    while (next != nullptr) {
        head = next;
        next = head->next;
        delete head;
    }
    head = nullptr;
    ending = nullptr;
}


#endif //LAB2_LINKEDLIST_H
