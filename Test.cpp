//
// Created by arina on 01.06.2021.
//
#include "Test.h"
#include "iostream"
#include "random"
#include "BinaryTree.h"

#define maxTreeSize 1000
#define maxSetSize 1000
#define maxElem 10000

int getRandomInt(int end) {
    return (int) random() % end;
}

int getRandomInt(int start, int end) {
    return (int) random()%(end - start) + start;
}

int Mult(int val) {
    return val * 3;
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

    for (int i = 0; i < count/2; i++) {
        binaryTree.Insert(i);
    }

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
            sum += val;
            binaryTree.Insert(j);
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

        auto *keys = subTree->GetValues();
        if (keys->GetLength() == 0) {
            passed++;
            delete keys;
            delete subTree;
            continue;
        }
        subTree->Insert(maxVal + 20);

        if (!binaryTree.FindSubTree(*subTree))
            passed++;

        delete keys;
        delete subTree;
    }

    if (debug)
        debugPrint(count, passed);
}
