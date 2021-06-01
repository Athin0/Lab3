//
// Created by arina on 01.06.2021.
//

#ifndef LAB3_HEAP_H
#define LAB3_HEAP_H

#include <iostream>
#include <string>
#include "LinkedListSequence.h"

using namespace std;

template<typename T>
class Heap
{
private:

    LinkedListSequence<T> *data;

    void klp(int id, Heap<T>* res)
    {
        int size=  data->GetLength();
        if(id>=size)
            return;
        res->Insert( data->Get(id));
        klp(id*2+1,res);
        klp(id*2+2,res);
    }

public:
    Heap()
    {
        data=new LinkedListSequence<T>();
    }
    Heap(T* item, int len)
    {
        data = new LinkedListSequence<T>();
        for(int i=0; i<len;i++)
             Insert(*(item+i));
    }
    Heap(Heap<T>& other)
    {
         data=new LinkedListSequence<T>(other.data);
    }

    void put_in_oder(int i=0)
    {
        int left, right;
        T temp;
        int HeapSize =  data->GetLength();
        left = 2*i+1;
        right = 2*i+2;
        if(left < HeapSize)
        {
            if( data->Get(i) <  data->Get(left))
            {

                temp =  data->Get(i);
                 data->Set(i, data->Get(left));
                 data->Set(left,temp);
                put_in_oder(left);
            }

        }
        if(right < HeapSize)
        {
            if( data->Get(i) <  data->Get(right))
            {

                temp =  data->Get(i);
                 data->Set(i, data->Get(right));
                 data->Set(right,temp);
                put_in_oder(right);
            }

        }
    }


    void Insert(T item)
    {
        int i, parent;
        i =  data->GetLength();
         data->Prepend(item);
        parent = (i-1)/2;
        while(parent >= 0 && i > 0)
        {
            if((* data)[i] > (* data)[parent])
            {
                int temp = (* data)[i];
                (* data)[i] = (* data)[parent];
                (* data)[parent] = temp;
            }
            i = parent;
            parent = (i-1)/2;
        }
    }

    T Get_max()
    {
        T max =  data->GetFirst();
        (* data)[0]= data->GetLast();
         data->del_last();
         put_in_oder();
        return max;
    }

    void out_heap()
    {
        int i = 0;
        int k = 1;
        int HeapSize =  data->GetLength();
        while(i < HeapSize)
        {
            while((i < k) && (i < HeapSize))
            {
                cout << ((* data)[i]) << " ";
                i++;
            }
            cout << endl;
            k = k * 2 + 1;
        }
    }

    void out(void)
    {
        int HeapSize =  data->GetLength();
        for(int i=0; i< HeapSize; i++)
        {
            cout << (* data)[i] << " ";
        }
        cout << endl;
    }
    void out_pair()
    {
        int size=  data->GetLength();
        int left, right;
        for(int i=0; i<size; i++)
        {
            left=2*i+1;
            right=2*i+2;
            cout<<"????????: "<< data->Get(i)<<endl;
            if(left<size)
                cout<<"????? ???????: "<< data->Get(left);
            if(right<size)
                cout<<" ?????? ???????: "<< data->Get(right);
            cout<<endl;

        }
    }
    int Find(T el)
    {

        int size= data->GetLength();
        int index=0;
        int left, right;
        while((index<size)&( data->Get(index)!=el))
            index++;
        if(index==size)
        {
            cout<<"???????? ???"<<endl;
            return nullptr;
        }

        return index;
    }



};
#endif //LAB3_HEAP_H
