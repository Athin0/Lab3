//
// Created by arina on 01.06.2021.
//
#include "Test.h"
#include "iostream"
#include "random"
#include "BinaryTree.h"

#define maxTreeSize 1000
#define maxElem 10000

int getRandomInt(int end) {
    return (int) random() % end;
}

int getRandomInt(int start, int end) {
    return (int) random()%(end - start) + start;
}

int Mult(int item, int val) {
    return item * val;
}

int Summ(int val1, int val2) {
    return val1 + val2;
}

void debugPrint(int count, int passed) {
    std::cout << "\tПройдено " << passed << "/" << count << " тестов. ";
    if (count == passed)
        std::cout << "Тест пройден!\n\n";
    else
        std::cout << "Тест не пройден!\n\n";
}

void test(int count, int debug) {
    testTree(count, debug);
}

void testTree(int count, int debug) {
    if (debug)
        std::cout << "Тестирование функций бинарного дерева:\n";

    testTreeInsert(count, debug);
    testTreeDelete(count, debug);
    testTreeFind(count, debug);

    testTreeMap(count, debug);
    testTreeReduce(count, debug);
    testTreeFindSub(count, debug);
}

void testTreeInsert(int count, int debug) {
    int passed = 0, i;
    if (debug)
        std::cout << "\tТестирование добавления в дерево:\n";

    BinaryTree<int> binaryTree;

    for (i = 0; i < count/2; i++) {
        binaryTree.Insert(i);
        if (binaryTree.Find(i))
            passed++;
    }
    int max = i-1;
    for (; i < count; i++) {
        int key = getRandomInt(max);
        if (binaryTree.Find(key))
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}



void testTreeDelete(int count, int debug) {
    int passed = 0;
    if (debug)
        std::cout << "\tТестирование удаления из дерева:\n";

    BinaryTree<int> binaryTree;

    for (int i = 0; i < count; i++) {
        binaryTree.Insert(i);
    }
    for (int i = count-1; i >= 0; i--){
        binaryTree.Remove(i);
        if(!binaryTree.Find(i))
            passed++;
    }

    if (debug)
        debugPrint(count, passed);
}


void testTreeFind(int count, int debug) {
    int passed = 0, i, k = 3;
    if (debug)
        std::cout << "\tТестирование поиска элемента в дереве:\n";
    BinaryTree<int> binaryTree;
    for (i = 0; i < count/2; i++) {
        binaryTree.Insert(i);
        if (binaryTree.Find(i))
            passed++;
    }
    int max = count / 2;

    for (; i < count; i++) {
        int item = getRandomInt(max);
        if (binaryTree.Find(item))
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}

void testTreeMap(int count, int debug) {
    int passed = 0, maxSize = maxTreeSize;
    if (debug)
        std::cout << "\tТестирование функции Map:\n";
    for (int i = 0; i < count; i++) {
        BinaryTree<int> binaryTree;
        for (int j = 0; j < maxSize; j++) {
            binaryTree.Insert(j);
        }
        auto *res = binaryTree.Map(Mult, 3);

        int correct = 1;
        for (int j = 0; j < maxSize && correct; j++) {
            if (!res->Find(j*3))
                correct = 0;
        }
        if (correct)
            passed++;

        delete res;
    }
    if (debug)
        debugPrint(count, passed);
}

void testTreeReduce(int count, int debug) {
    int passed = 0, maxSize = maxTreeSize, maxVal = maxElem;
    if (debug)
        std::cout << "\tТестирование функции Reduce:\n";
    for (int i = 0; i < count; i++) {
        BinaryTree<int> binaryTree;
        int sum = 0;
        for (int j = 0; j < maxSize; j++) {
            int val = getRandomInt(maxVal);
            if (!binaryTree.Find(val)) {
                sum += val;
                binaryTree.Insert(val);
            }
        }

        int res = binaryTree.Reduce(Summ, 0);
        if (sum == res)
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}

void testTreeFindSub(int count, int debug) {
    int passed = 0, maxSize = maxTreeSize, maxVal = maxElem;
    if (debug)
        std::cout << "\tТестирование поиска поддерева:\n";
    for (int i = 0; i < count; i++) {
        BinaryTree<int> binaryTree;
        for (int j = 0; j < maxSize; j++) {
            binaryTree.Insert(j);
        }

        auto *subTree = binaryTree.SubTree(getRandomInt(maxSize));

        if (!binaryTree.FindSubTree(*subTree)) {
            delete subTree;
            continue;
        }

        subTree->Insert(maxVal + 20);

        if (!binaryTree.FindSubTree(*subTree))
            passed++;

        delete subTree;
    }

    if (debug)
        debugPrint(count, passed);
}
