//
// Created by arina on 31.05.2021.
//

#ifndef LAB3_MENUTREE_H
#define LAB3_MENUTREE_H
#include <complex>
#include <iostream>
//#include "tests/test.h"
#include "BinaryTree.h"
#include "DynamicArraySequence.h"
#include "baseFunc.h"
void mainMenuBinaryTree();

//1
void readBinaryTree(ArraySequence<BinaryTree<int>*> *intArr,
ArraySequence<BinaryTree<float>*> *floatArr);

template<class T>
void readTypeBinaryTree(ArraySequence<BinaryTree<T>*> *arr, int count);

template<class T>
void generateRandomBinaryTree(ArraySequence<BinaryTree<T>*> *arr, int count, T (*funcT)());

//2
void operationWithBinaryTree(ArraySequence<BinaryTree<int>*> *intArr,
ArraySequence<BinaryTree<float>*> *floatArr);

template<class T>
void operationTypeWithBinaryTree(ArraySequence<BinaryTree<T>*> *arr);

//3
void printBinaryTree(ArraySequence<BinaryTree<int>*> *intArr,
ArraySequence<BinaryTree<float>*> *floatArr);

template<class T>
void printTypeBinaryTree(ArraySequence<BinaryTree<T>*> *arr);


//4
void deleteBinaryTree(ArraySequence<BinaryTree<int>*> *intArr,
ArraySequence<BinaryTree<float>*> *floatArr);

template<class T>
void deleteTypeBinaryTree(ArraySequence<BinaryTree<T>*> *arr);

//5
void testFuncBinaryTree();

#endif //LAB3_MENUTREE_H
