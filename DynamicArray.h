//
// Created by arina on 09.04.2021.
//

#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H
#include <iostream>

using namespace std;


template<class T>
void arrCopy(T *out_arr, T *inp_arr, int count) {
    for (int i = 0; i < count; i++) {
        out_arr[i] = inp_arr[i];
    }
}

template<class T>
class DynamicArray {
private:
    T *arr= nullptr;
    size_t size=0;
public:
    class IndexOutOfRange {
    };

    DynamicArray();

    explicit DynamicArray(int NewSize);

    DynamicArray(T *items, int count);

    DynamicArray(DynamicArray<T> const &DynamicArray);

    ~DynamicArray();

    T Get(int index) const;

    T& operator [] (int index) {
        if (index < 0 || index >= size)
            throw IndexOutOfRange();

        return arr[index];
    }

    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.size);
        for (int i = 0; i < size; i++) {
            arr[i] = dynamicArray.arr[i];
        }
        return *this;
    }

    void Reverse() {
        for (auto i = 0; i < GetLength() / 2; i++) {
            int index = GetLength() - 1 - i;
            T item = arr[i];
            arr[i] = arr[index];
            arr[index] = item;
        }
    }

    int GetLength() const;

    void Set(int index, T value);

    void Resize(int newSize);

    template<class U>
    DynamicArray<U>* Map(U (*func)(T item)) {
        auto *res = new DynamicArray<U>;
        res->Resize(size);
        for (int i = 0; i <size; i++) {
            (*res)[i] = func(arr[i]);
        }

        return res;
    }

    template<class U>
    DynamicArray<U>* Map(U (*func)(T item1, T item2), T item) {
        auto *res = new DynamicArray<U>;
        res->Resize(size);
        for (int i = 0; i < size; i++) {
            (*res)[i] = func(arr[i], item);
        }
        return res;
    }

    template<class U>
    T Reduce(U (*func)(T item1, T item2)) {
        if (size < 2) throw IndexOutOfRange(size, 1);

        auto res = func(arr[0], arr[1]);
        for (int i = 2; i < size; i++) {
            res = func(res, arr[i]);
        }
        return res;
    }

};

template<class T>
DynamicArray<T>::DynamicArray() {
    arr = nullptr;
    size = 0;
}

template<class T>
DynamicArray<T>::DynamicArray(int NewSize) {
    arr = nullptr;
    size = NewSize;
    Resize(size);
};


template<class T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    arr = nullptr;
    size = 0;
    if (count < 0) return;           //создание нового пустого массива и копирование в него данных из исходного
    Resize(count);
    for (int i = 0; i < size; i++) {
        arr[i] = items[i];
    }
}

template<class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> const &dynamicArray) {
    arr = nullptr; //создание нового массива и копирование элементов из такого же класса
    size = 0;
    if (dynamicArray.size == 0 || dynamicArray.arr == nullptr) return;
    Resize(dynamicArray.size);
    for (int i = 0; i < size; i++) {
        arr[i] = dynamicArray.arr[i];
    }
}

template<class T>
DynamicArray<T>::~DynamicArray() {      //удаление массива
    if (arr != nullptr && size != 0)
        delete[] arr;
}

template<class T>
T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index > size)
        throw IndexOutOfRange();
    return arr[index];
}

template<class T>
int DynamicArray<T>::GetLength() const {           //получить размер массива
    return size;
}

template<class T>
void DynamicArray<T>::Set(int index, T value) {               //Задать элемент по индексу
    if (index < 0 || index >= size)
        throw IndexOutOfRange();
    arr[index] = value;
}


template<class T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0)
        throw IndexOutOfRange(); //исключение выхода за массив
    if (size == newSize) return;               //длина не изменилась
    if (newSize == 0) {                       //нулевая длина, удаление массива
        if (arr != nullptr)
            delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    } else if (newSize > size) {              //создание нового массива с выделением памяти и заполнение данных
        T *arrNew = new T[newSize];
        if (arr != nullptr) {
            arrCopy(arrNew, arr, size);
            delete[] arr;
        }
        arr = arrNew;
        size = newSize;
    } else if (newSize < size) {            //создание нового массива с освобождением памяти и заполнение данных
        T *arrNew = new T[newSize];
        if (arr != nullptr) {
            arrCopy(arrNew, arr, newSize);
            delete[] arr;
        }
        arr = arrNew;
        size = newSize;
    }

}

template<class T>
std::ostream &operator << (std::ostream &cout, DynamicArray<T> dynamicArray) {
    /*cout << '{';
    for (int i = 0; i < dynamicArray.GetLength(); i++) {
        cout << dynamicArray[i];
        if (i < dynamicArray.GetLength() - 1) {
            cout << ", ";
        }
    }*/
    return cout << &dynamicArray;
}


template<class T>
std::ostream &operator << (std::ostream &cout, DynamicArray<T> *dynamicArray) {
    cout << '{';
    for (int i = 0; i < dynamicArray->GetLength(); i++) {
        cout << (*dynamicArray)[i];
        if (i < dynamicArray->GetLength() - 1) {
            cout << ", ";
        }
    }
    return cout << '}';
}
#endif //LAB2_DYNAMICARRAY_H
