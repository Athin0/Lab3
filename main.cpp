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
//#include "search_tree.h
#include "BinaryTree.h"
using namespace std;


bool func(int k) {
    return k > 20;
}

int func3(int k1, int k2) {
    return k1*k2;
}

int main() {
    BinaryTree<int> t;
    t.Insert(15);
    t.Insert(20);
    t.Insert(25);
    t.Insert(10);
//    t.GetStrGreatTree();
    t.Insert(30);
    t.Insert(11);
    t.Insert(31);
    t.Insert(3);
    t.Insert(34);
    t.Insert(35);
    t.Insert(38);

    t.Insert(234);
    t.Insert(23);
//    t.GetStrGreatTree();
//    BinaryTree<int> *a;
//    t.Remove(20);
//    t.GetStrGreatTree();
//    t.Remove(25);
//    t.GetStrGreatTree();
//    t.Remove(30);

    cout << t.GetStrGreatTree();
    cout<< *t.Where(func) << endl;
    cout<< *t.Map(func3, 3) << endl;
    cout<< *t.Map(func3, 5) << endl;
    mainMenuBinaryTree();
    return 0;
}




