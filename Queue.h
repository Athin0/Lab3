//
// Created by arina on 29.05.2021.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "BinaryTree.h"

using namespace std;

class PriorityFull{
public:
    PriorityFull(){};
};
template<class T, class K>
class Queue {
private:

    BinaryTree<T, K> *data;

public:

    Queue() {
        data = new BinaryTree<T, K>();
    }

    Queue(T *item, K *itemVal, int len) {
        data = new BinaryTree<T, K>(item, itemVal, len);
    }

    explicit Queue(const BinaryTree<T, K> &other) {
        data = new BinaryTree<T, K>(other);
    }

    explicit Queue(ArraySequence<T> &otherKey, ArraySequence<K> &otherVal) {
        data = new BinaryTree<T, K>(otherKey, otherVal);
    }

    Queue(const Queue<T, K> &other) {
        data = new BinaryTree<T, K>(*other.data);
    }

    ~Queue(){
        delete data;
    }

    Queue<T, K> &operator=(const Queue<T, K> &other) {
        delete this;
        data = new BinaryTree<T,K >(other.data);
        return *this;
    }


    void Insert(T data, K value) {
        if (Find(data))
            throw PriorityFull();
        (this->data)->Insert(data, value);
    }
    void Remove(T data) {
        (this->data)->Remove(data);
    }
    bool Find(T key) {
        bool res= data->Find(key);
        return res;
    }

    K FindVal(T key) {
        K res;
        res = data->GetValueKey(key);
        return res;
    }

    K GetMax() {
        ArraySequence<T> *r;
        r = data->GetValues();
        T res = r->Get(r->GetLength() - 1);
        K resVal = data->GetValueKey(res);
        return resVal;
    }

    K GetMin() {
        ArraySequence<T> *r;
        r = data->GetValues();
        T res = r->Get(0);
        K resVal = data->GetValueKey(res);
        return resVal;
    }


    Queue<T, K> *Map(T(*func)(T)) {
        BinaryTree<T, K> *p1 = data->Map(func);
        Queue<T, K> *res = new Queue<T, K>(*p1);
        return res;
    }

    Queue<T, K> *Map(T(*func)(void)) {
        BinaryTree<T, K> *p1 = data->Map(func);
        Queue<T, K> *res = new Queue<T, K>(*p1);
        return res;
    }

    Queue<T, K> *Where(bool(*func)(T)) {
        BinaryTree<T, K> *p1 = data->Where(func);
        Queue<T, K> *res = new Queue<T, K>(*p1);
        return res;
    }

    K Reduce(K(*func)(K, K), K item) {
        K res = data->Reduce(func, item);
        return res;
    }


    void Print() {
        ArraySequence<T> *key = data->GetKeyArray();
        ArraySequence<K> *value = data->GetValuesArray();
        for (int i = 0; i < key->GetLength(); i++) {
            cout << "Приоритет:" << key->Get(i) << " Данные:" << value->Get(i) << endl;
        }
    }

    bool FindSubSequence(Queue<T, K> &other) {
        BinaryTree<T, K> *d1 = data;
        BinaryTree<T, K> *d2 = other.data;
        return d1->FindSubTree(*d2);
    }
    bool FindSubSequence0(Queue<T, K> &other) {
        return true;
    }


    Queue *SubSequence(int start, int end) {
        ArraySequence<T> *d1 = data->GetKeyArray();
        ArraySequence<K> *d1val = data->GetValuesArray();
        ArraySequence<T> *d2 = d1->GetSubSequence(start, end);
        ArraySequence<T> *d2val = d1val->GetSubSequence(start, end);
        BinaryTree<T, K> *p = new BinaryTree<T, K>(d2, d2val);
        Queue<T, K> *res = new Queue<T, K>(*p);
        return res;
    }


};

template<class T, class K>
std::ostream &operator<<(std::ostream &cout, Queue<T, K> &queue) {
    queue.Print();
    return cout;
}

#endif // QUEUE_H
