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
void readBinaryTree(ArraySequence<BinaryTree<int, int>*> *intArr,
ArraySequence<BinaryTree<float, float>*> *floatArr);

template<class T, class K>
void readTypeBinaryTree(ArraySequence<BinaryTree<T, K>*> *arr, int count);

template<class T, class K>
void generateRandomBinaryTree(ArraySequence<BinaryTree<T, K>*> *arr, int count, T (*funcT)());

//2
void operationWithBinaryTree(ArraySequence<BinaryTree<int, int>*> *intArr,
ArraySequence<BinaryTree<float, float>*> *floatArr);

template<class T, class K>
void operationTypeWithBinaryTree(ArraySequence<BinaryTree<T, K>*> *arr);

//3
void printBinaryTree(ArraySequence<BinaryTree<int, int>*> *intArr,
ArraySequence<BinaryTree<float, float>*> *floatArr);

template<class T, class K>
void printTypeBinaryTree(ArraySequence<BinaryTree<T, K>*> *arr);


//4
void deleteBinaryTree(ArraySequence<BinaryTree<int, int>*> *intArr,
ArraySequence<BinaryTree<float, float>*> *floatArr);

template<class T, class K>
void deleteTypeBinaryTree(ArraySequence<BinaryTree<T, K>*> *arr);

//5
void testFuncBinaryTree();

#endif //LAB3_MENUTREE_H
