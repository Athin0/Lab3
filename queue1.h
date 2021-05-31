#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "array1.h"
#include "search_tree1.h"
using namespace std;

template <typename T>
class Queue
{
private:

    Search_tree<T>* data;


public:

    Queue()
    {
        data = new Search_tree<T>();
    }
    Queue(T* item, int len)
    {
        data = new Search_tree<T>(item,len);
    }
    Queue(Search_tree<T>& other)
    {
        data = new Search_tree<T>(other);
    }
    Queue(Queue<T>& other)
    {
        data = new Search_tree<T>(other.data);
    }

    bool nun()
    {
        bool a=(this->data->get_length()==0);
        return a;
    }

    void add_el(T data)
    {
        this->data->add_el(data);
    }

    T get_max()
    {
        D_Array<T> *r= this->data->lkp_t();
        T res = r->p_back();
        this->data= new Search_tree<T>(r);
        return res;
    }

    T get_min()
    {
        D_Array<T> *r= this->data->lkp_t();
        T res= r->p_front();
        this->data= new Search_tree<T>(r);
        return res;
    }

    Queue<T>* concat(Queue<T>& other)
    {
        D_Array<T>* d1= this->data->klp_t();
        D_Array<T>* d2= other.data->klp_t();
        D_Array<T>* d3= d1->concat(d2);
        Search_tree<T>* p= new Search_tree<T>(d3);
        Queue<T> * res= new Queue<T>(*p);
        return res;
    }

    Queue<T>* map(T(*func)(T))
    {
        Search_tree<T>* p1= this->data->map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* map(T(*func)(void))
    {
        Search_tree<T>* p1= this->data->map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* where(bool(*func)(T))
    {
        Search_tree<T>* p1= this->data->where(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    T reduce(T(*func)(T))
    {
        Search_tree<T>* p1= this->data->reduce(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    void print()
    {
        D_Array<T>* temp = this->data->klp_t();
        temp->Array_Output();
    }


    int find_subsequence(Queue<T>& other)
    {
        D_Array<T> * d1=this->data->klp_t();
        D_Array<T> * d2=other.data->klp_t();
        int index = d1->find_subsequence(*d2);
        return index;
    }

    int find_subsequence(T* item, int len)
    {
        D_Array<T> * d1=this->data->klp_t();
        int index = d1->find_subsequence(item,len);
        return index;
    }

    Queue* get_subsequence(int start, int end)
    {
        D_Array<T> * d1=this->data->klp_t();
        D_Array<T> * d2=d1->get_subsequence(start, end);
        Search_tree<T>* p= new Search_tree<T>(d2);
        Queue<T> * res= new Queue<T>(*p);
        return res;
    }



};
#endif // QUEUE_H
