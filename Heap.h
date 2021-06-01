//
// Created by arina on 30.05.2021.
//

#ifndef LAB3_HEAP_H
#define LAB3_HEAP_H

#include <iostream>
#include <string>
#include "LinkedListSequence.h"

using namespace std;

template<typename T>
class Heap {
private:

    LinkedListSequence<T> *data;

    void KLR(int id, Heap<T> *res) {
        int size = data->GetLength();
        if (id >= size)
            return;
        res->Insert(data->Get(id));
        KLR(id * 2 + 1, res);
        KLR(id * 2 + 2, res);
    }

    std::string GetStr(int index, int level) const {
        if (index >= data->GetLength())
            return std::string();

        std::string res;
        res += GetStr(index * 2 + 2, level + 1);
        for (int i = 0; i < level; i++)
            res += "     ";

        res += std::to_string((*data)[index]);
        res += '\n';
        res += GetStr(index * 2 + 1, level + 1);

        return res;
    }

    int FindIndex(T element) {

        int size = data->GetLength();
        int index = 0;
        int left, right;
        while ((index < size) & (data->Get(index) != element))
            index++;
        if (index == size) {
            return -1;
        }

        return index;
    }

public:
    Heap() {
        data = new LinkedListSequence<T>();
    }

    Heap(T *item, int len) {
        data = new LinkedListSequence<T>();
        for (int i = 0; i < len; i++)
            Insert(*(item + i));
    }

    Heap(Heap<T> &other) {
        data = new LinkedListSequence<T>(other.data);
    }

    ~Heap() {
        delete data;
    }

    void Balance(int i = 0) {
        int left, right;
        T temp;
        int HeapSize = data->GetLength();
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < HeapSize) {
            if (data->Get(i) < data->Get(left)) {
                temp = data->Get(i);
                data->Set(i, data->Get(left));
                data->Set(left, temp);
                Balance(left);
            }
        }
        if (right < HeapSize) {
            if (data->Get(i) < data->Get(right)) {
                temp = data->Get(i);
                data->Set(i, data->Get(right));
                data->Set(right, temp);
                Balance(right);
            }
        }
    }


    void Insert(T item) {
        int i, parent;
        i = data->GetLength();
        data->Append(item);
        parent = (i - 1) / 2;
        while (parent >= 0 && i > 0) {
            if ((*data)[i] > (*data)[parent]) {
                int temp = (*data)[i];
                (*data)[i] = (*data)[parent];
                (*data)[parent] = temp;
            }
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    T GetMax() {
        T max = data->GetFirst();
        ((*data)[0]) = data->GetLast();
        data->PopEnd();
        Balance();
        return max;
    }

    std::string GetStr() {
        return GetStr(0, 0);
    }
    std::string out_pair()
    {
        int size= this->data->GetLength();
        int left, right;
        std::string res;
        for(int i=0; i<size; i++)
        {
            left=2*i+1;
            right=2*i+2;
            if (left >= size && right >= size)
                continue;
            res += "Корень: ";
            res += std::to_string(data->Get(i));
            if(left<size) {
                res += ", Лево: ";
                res += std::to_string(data->Get(left));
            }
            if(right<size) {
                res += ", Право: ";
                res += std::to_string(data->Get(right));
            }
            res += '\n';
        }
        return res;
    }


    bool Find(T element) {
        return FindIndex(element) != -1;
    }
};

template<class T>
std::ostream &operator<<(std::ostream &cout, Heap<T> &heap) {
    return cout << heap.GetStr();
}

#endif //LAB3_HEAP_H
