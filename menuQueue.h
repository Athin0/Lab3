//
// Created by arina on 06.06.2021.
//

#ifndef LAB3_MENUQUEUE_H
#define LAB3_MENUQUEUE_H

#include "Queue.h"
#include <complex>
#include <iostream>
#include "DynamicArraySequence.h"
#include "baseFunc.h"

void mainMenuQueue();

//1
void readQueue(ArraySequence<Queue<int, int>*> *intArr,
                    ArraySequence<Queue<float, float>*> *floatArr);

template<class T, class K>
void readTypeQueue(ArraySequence<Queue<T, K>*> *arr, int count);

template<class T, class K>
void generateRandomQueue(ArraySequence<Queue<T, K>*> *arr, int count, T (*funcT)());

//2
void operationWithQueue(ArraySequence<Queue<int, int>*> *intArr,
                             ArraySequence<Queue<float, float>*> *floatArr);

template<class T, class K>
void operationTypeWithQueue(ArraySequence<Queue<T, K>*> *arr);

//3
void printQueue(ArraySequence<Queue<int, int>*> *intArr,
                     ArraySequence<Queue<float, float>*> *floatArr);

template<class T, class K>
void printTypeQueue(ArraySequence<Queue<T, K>*> *arr);


//4
void deleteQueue(ArraySequence<Queue<int, int>*> *intArr,
                      ArraySequence<Queue<float, float>*> *floatArr);

template<class T, class K>
void deleteTypeQueue(ArraySequence<Queue<T, K>*> *arr);

//5
void testFuncQueue();

#endif //LAB3_MENUQUEUE_H
