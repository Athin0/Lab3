//
// Created by arina on 28.05.2021.
//

#include <iostream>
#include <algorithm>
#include <string>
#include "menuTree.h"
#include <random>
#include <ctime>
#include <complex>
#include "Heap.h"
#include "BinaryTree.h"
#include "MenuHeap.h"
using namespace std;


bool func(int k) {
    return k > 20;
}

int func3(int k1, int k2) {
    return k1*k2;
}

int main() {

    mainMenuHeap();
    //mainMenuBinaryTree();
    return 0;
}
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



