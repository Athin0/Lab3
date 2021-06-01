//
// Created by arina on 29.05.2021.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "BinaryTree.h"
using namespace std;


template <typename T>
class Queue
{
private:

    BinaryTree<T>* data;


public:

    Queue()
    {
        data = new BinaryTree<T>();
    }
    Queue(T* item, int len)
    {
        data = new BinaryTree<T>(item,len);
    }
    Queue(BinaryTree<T>& other)
    {
        data = new BinaryTree<T>(other);
    }
    Queue(Queue<T>& other)
    {
        data = new BinaryTree<T>(other.data);
    }


    void Insert(T data)
    {
        data->Insert(data);
    }

    T get_max()
    {
        ArraySequence<T> *r;
        r= data->GetValues();
        T res = r->Get(r->GetLength()-1);
        return res;
    }

    T get_min()
    {
        ArraySequence<T> *r;
        r= data->GetValues();
        T res = r->Get(0);
        return res;
    }
    

    Queue<T>* Map(T(*func)(T))
    {
        BinaryTree<T>* p1= data->Map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* Map(T(*func)(void))
    {
        BinaryTree<T>* p1= data->Map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* Where(bool(*func)(T))
    {
        BinaryTree<T>* p1= data->Where(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    T Reduce(T(*func)(T))
    {
        BinaryTree<T>* p1= data->Reduce(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    void Print()
    {
        ArraySequence<T>* temp = data->GetValues();
        cout<< temp;
    }


    int SubSequence(Queue<T>& other)
    {
        ArraySequence<T> * d1=data->GetValues();
        ArraySequence<T> * d2=other.data->GetValues();
        int index = d1->GetSubSequence(*d2);
        return index;
    }

    int SubSequence(T* item, int len)
    {
        ArraySequence<T> * d1=data->GetValues();
        int index = d1->(item,len);
        return index;
    }

    Queue* SubSequence(int start, int end)
    {
        ArraySequence<T> * d1=data->GetValues();
        ArraySequence<T> * d2=d1->GetSubSequence(start, end);
        BinaryTree<T>* p= new BinaryTree<T>(d2);
        Queue<T> * res= new Queue<T>(*p);
        return res;
    }



};
#endif // QUEUE_H
