//
// Created by arina on 06.05.2021.
//

#ifndef LAB2_ArraySequence_H
#define LAB2_ArraySequence_H

#include "Sequence.h"
#include "DynamicArray.h"
#include "DynamicArray.cpp"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> dynamicArray;
public:
    class IndexOutOfRange {
    private:
        int length;
        int index;
    public:
        IndexOutOfRange(int length, int index) : length(length), index(index) {};

        IndexOutOfRange() : length(-1), index(-1) {};
    };


    ArraySequence() {
        dynamicArray = DynamicArray<T>();
    }

    ArraySequence(T *items, int count) {
        dynamicArray = DynamicArray<T>(items, count);
    }

    explicit ArraySequence(const DynamicArray<T> &array) {
        dynamicArray = array;
    }

    T GetFirst() {
        if (GetLength() == 0)
            throw IndexOutOfRange(GetLength(), 0);
        return dynamicArray.Get(0);
    }

    T GetLast() {
        if (GetLength() == 0)
            throw IndexOutOfRange(GetLength(), -1);
        return dynamicArray.Get(dynamicArray.GetLength() - 1);
    }

    T Get(int index) const {
        if (index < 0 || index >= GetLength())
            throw IndexOutOfRange(GetLength(), index);
        return dynamicArray.Get(index);
    }

    void Set(T item,int index) {
        if (index < 0 || index >= GetLength())
            throw IndexOutOfRange(GetLength(), index);
        dynamicArray.Set(index, item);
    }

    T &operator[](int index) {
        if (index < 0 || index >= GetLength())
            throw IndexOutOfRange(GetLength(), index);
        return dynamicArray[index];
    }


    ArraySequence<T> &operator=(ArraySequence<T> arraySequence) {
        dynamicArray = arraySequence.dynamicArray;
        return *this;
    }


    ArraySequence<T> *GetSubSequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= GetLength())
            throw IndexOutOfRange(GetLength(), startIndex);
        if (endIndex < 0 || endIndex > GetLength())
            throw IndexOutOfRange(GetLength(), endIndex);

        auto newArray = new ArraySequence<T>;
        for (int i = startIndex; i != endIndex; i++) {
            newArray->Append(dynamicArray[i]);
        }

        return newArray;
    }

    int GetLength() const {
        return dynamicArray.GetLength();
    }

    void Append(T item) {
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        dynamicArray.Set(dynamicArray.GetLength() - 1, item);
    }


    void Prepend(T item) {
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        for (int i = dynamicArray.GetLength() - 2; i >= 0; i--) {
            dynamicArray[i + 1] = dynamicArray[i];
        }
        dynamicArray.Set(0, item);
    }

    void Insert(T item, int index) {
        if (index < 0 || index >= dynamicArray.GetLength())
            throw IndexOutOfRange(dynamicArray.GetLength(), index);
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        for (int i = dynamicArray.GetLength() - 2; i >= index; i--) {
            dynamicArray[i + 1] = dynamicArray[i];
        }
        dynamicArray[index] = item;
    }


    ArraySequence<T> *Concat(Sequence<T> *sequence) {
        int start = dynamicArray.GetLength();
        dynamicArray.Resize(start + sequence->GetLength());

        for (int i = 0; i < sequence->GetLength(); i++) {
            dynamicArray[start + i] = (*sequence)[i];
        }

        return this;
    }
    void Reverse() {
        dynamicArray.Reverse();
    }
    T Pop() {
        if (dynamicArray.GetLength() == 0)
            throw IndexOutOfRange(0, -1);
        T item = dynamicArray[dynamicArray.GetLength() - 1];
        dynamicArray.Resize(dynamicArray.GetLength() - 1);
        return item;
    }

    T Pop(int index) {
        if (index < 0 || index >= dynamicArray.GetLength())
            throw IndexOutOfRange(dynamicArray.GetLength(), index);

        T item = dynamicArray[index];
        for (int i = index; i < dynamicArray.GetLength() - 1; i++) {
            dynamicArray[i] = dynamicArray[i + 1];
        }
        dynamicArray.Resize(dynamicArray.GetLength() - 1);
        return item;
    }

    template<class U>
    ArraySequence<U> *Map(U (*func)(T item)) {
        auto *res = new ArraySequence<U>;
        auto *arr = dynamicArray.Map(func);
        for (int i = 0;i < arr->GetLength();i++) {
            res->Append((*arr)[i]);
        }
        delete arr;
        return res;
    }

    template<class U>
    ArraySequence<U> *Map(U (*func)(T item1, T item2), T item) {
        auto *res = new ArraySequence<U>;
        res->dynamicArray = *dynamicArray.Map(func, item);
        return res;
    }

    template<class U>
    U Reduce(U (*func)(T item1, T item2), T item) {
        return dynamicArray.Reduce(func,item);
    }

    ArraySequence<T>* Where(bool(*func)(T))
    {
        ArraySequence<T> *temp=new ArraySequence<T>();
        T data_t;
        int len=GetLength();
        for(int i=0;i<len;i++)
        {
            data_t=Get(i);
            if(func(data_t))
            {
                temp->Append(data_t);
            }
        }
        return temp;
    }
};
template<class T>
std::ostream &operator<<(std::ostream &cout, ArraySequence<T>arraySequence) {
    cout << '{';
    for (int i = 0; i < arraySequence.GetLength(); i++) {
        cout << arraySequence[i];
        if (i != arraySequence.GetLength() - 1) {
            cout << ", ";
        }
    }
    cout << '}';
    return cout;
}
#endif //LAB2_ArraySequence_H

/*
int operator==(ArraySequence<T> vector_arr) {
    return dynamicArray == vector_arr.dynamicArray;
}
/**/