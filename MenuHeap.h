//
// Created by arina on 01.06.2021.
//

#ifndef LAB3_MENUHEAP_H
#define LAB3_MENUHEAP_H
#include <complex>
#include <iostream>
//#include "tests/test.h"
#include "Heap.h"
#include "DynamicArraySequence.h"
#include "baseFunc.h"
void mainMenuHeap();

//1
void readHeap(ArraySequence<Heap<int>*> *intArr,
                    ArraySequence<Heap<float>*> *floatArr);

template<class T>
void readTypeHeap(ArraySequence<Heap<T>*> *arr, int count);

template<class T>
void generateRandomHeap(ArraySequence<Heap<T>*> *arr, int count, T (*funcT)());

//2
void operationWithHeap(ArraySequence<Heap<int>*> *intArr,
                             ArraySequence<Heap<float>*> *floatArr);

template<class T>
void operationTypeWithHeap(ArraySequence<Heap<T>*> *arr);

//3
void printHeap(ArraySequence<Heap<int>*> *intArr,
                     ArraySequence<Heap<float>*> *floatArr);

template<class T>
void printTypeHeap(ArraySequence<Heap<T>*> *arr);


//4
void deleteHeap(ArraySequence<Heap<int>*> *intArr,
                      ArraySequence<Heap<float>*> *floatArr);

template<class T>
void deleteTypeHeap(ArraySequence<Heap<T>*> *arr);

//5
void testFuncHeap();


#endif //LAB3_MENUHEAP_H
