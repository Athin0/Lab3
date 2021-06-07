//
// Created by arina on 28.05.2021.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>

#include "Heap.h"
#include "BinaryTree.h"

#include "menuTree.h"
#include "MenuHeap.h"
#include "menuQueue.h"
#include "Queue.h"
using namespace std;



bool func(int k) {
    return (k < 7)&& !(k%2) ;
}
int func3(int k1, int k2) {
    return k1 * k2;
}
int func4(int k1) {
    return k1 * 3;
}

int main() {
    //mainMenuHeap();
    //mainMenuBinaryTree();
    mainMenuQueue();

    return 0;
}
//
//Queue<int, int> t;
//for (int i=0;i<10;i++) {
//t.Insert(i, i);
//}
//Queue<int,int>* q= t.Where(func);
//cout<< t.Reduce(func3,1);
//q->Print();

//}
//    BinaryTree<int> t;
//    t.Insert(15);
//    t.Insert(20);
//    t.Insert(25);
//    t.Insert(10);
//    t.Insert(30);
//    t.Insert(11);
//    t.Insert(31);
//    t.Insert(3);
//    t.Insert(34);
//    t.Insert(35);
//    t.Insert(38);
//    t.Insert(234);
//    t.Insert(23);

//cout << t.GetStrGreatTree();
// cout<< *t.Where(func) << endl;
//    cout<< *t.Map(func3, 3) << endl;
//cout<< *t.Map(func3, 5) << endl;



