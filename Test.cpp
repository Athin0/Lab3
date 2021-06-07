//
// Created by arina on 01.06.2021.
//
#include "Test.h"
#include "iostream"
#include "random"
#include "BinaryTree.h"
#include "Queue.h"
#define maxTreeSize 1000
#define maxQueueSize 1000
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
    testQueue( count, debug);
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

    BinaryTree<int,int> binaryTree;

    for (i = 0; i < count/2; i++) {
        binaryTree.Insert(i,0);
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

    BinaryTree<int,int> binaryTree;

    for (int i = 0; i < count; i++) {
        binaryTree.Insert(i,0);
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
    BinaryTree<int,int > binaryTree;
    for (i = 0; i < count/2; i++) {
        binaryTree.Insert(i,0);
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
        BinaryTree<int,int> binaryTree;
        for (int j = 0; j < maxSize; j++) {
            binaryTree.Insert(j,j);
        }
        auto *res = binaryTree.Map(Mult, 3);

        int correct = 1;
        for (int j = 0; j < maxSize && correct; j++) {
            if ((res->GetValueKey(j)!= j*3))
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
        BinaryTree<int, int> binaryTree;
        int sum = 0;
        for (int j = 0; j < maxSize; j++) {
            int key = getRandomInt(maxVal);
            int val = getRandomInt(maxVal);
            if (!binaryTree.Find(key)) {
                sum += val;
                binaryTree.Insert(key, val);
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
        BinaryTree<int,int> binaryTree;
        for (int j = 0; j < maxSize; j++) {
            binaryTree.Insert(j,0);
        }

        auto *subTree = binaryTree.SubTree(getRandomInt(maxSize));

        if (!binaryTree.FindSubTree(*subTree)) {
            delete subTree;
            continue;
        }

        subTree->Insert(maxVal + 20,0);

        if (!binaryTree.FindSubTree(*subTree))
            passed++;

        delete subTree;
    }

    if (debug)
        debugPrint(count, passed);
}


void testQueue(int count, int debug) {
    if (debug)
        std::cout << "Тестирование функций очереди:\n";

    testQueueInsert(count, debug);
    testQueueDelete(count, debug);
    testQueueFind(count, debug);

    testQueueMap(count, debug);
    testQueueReduce(count, debug);
    testQueueFindSub(count, debug);
}

void testQueueInsert(int count, int debug) {
    int passed = 0, i;
    if (debug)
        std::cout << "\tТестирование добавления в очередь:\n";

    Queue<int,int> queue;

    for (i = 0; i < count/2; i++) {
        queue.Insert(i,0);
        if (queue.Find(i))
            passed++;
    }
    int max = i-1;
    for (; i < count; i++) {
        int key = getRandomInt(max);
        if (queue.Find(key))
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}



void testQueueDelete(int count, int debug) {
    int passed = 0;
    if (debug)
        std::cout << "\tТестирование удаления из очереди:\n";

    Queue<int,int> queue;

    for (int i = 0; i < count; i++) {
        queue.Insert(i,0);
    }
    for (int i = count-1; i >= 0; i--){
        queue.Remove(i);
        if(!queue.Find(i))
            passed++;
    }

    if (debug)
        debugPrint(count, passed);
}


void testQueueFind(int count, int debug) {
    int passed = 0, i, k = 3;
    if (debug)
        std::cout << "\tТестирование поиска элемента в очереди:\n";
    Queue<int,int > queue;
    for (i = 0; i < count/2; i++) {
        queue.Insert(i,0);
        if (queue.Find(i))
            passed++;
    }
    int max = count / 2;

    for (; i < count; i++) {
        int item = getRandomInt(max);
        if (queue.Find(item))
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}

void testQueueMap(int count, int debug) {
    int passed = 0, maxSize = maxQueueSize;
    if (debug)
        std::cout << "\tТестирование функции Map:\n";
    for (int i = 0; i < count; i++) {
        Queue<int,int> queue;
        for (int j = 0; j < maxSize; j++) {
            queue.Insert(j,j);
        }
        auto *res = queue.Map(Mult, 3);

        int correct = 1;
        for (int j = 0; j < maxSize && correct; j++) {
            if ((res->FindVal(j) != j*3))
                correct = 0;
        }
        if (correct)
            passed++;
        delete res;
    }
    if (debug)
        debugPrint(count, passed);
}

void testQueueReduce(int count, int debug) {
    int passed = 0, maxSize = maxQueueSize, maxVal = maxElem;
    if (debug)
        std::cout << "\tТестирование функции Reduce:\n";
    for (int i = 0; i < count; i++) {
        Queue<int, int> queue;
        int sum = 0;
        for (int j = 0; j < maxSize; j++) {
            int key = getRandomInt(maxVal);
            int val = getRandomInt(maxVal);
            if (!queue.Find(key)) {
                sum += val;
                queue.Insert(key, val);
            }
        }
        int res = queue.Reduce(Summ, 0);
        if (sum == res)
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}

void testQueueFindSub(int count, int debug) {
    int passed = 0, maxSize = maxQueueSize, maxVal = maxElem;
    if (debug)
        std::cout << "\tТестирование поиска поддерева:\n";
    for (int i = 0; i < count; i++) {
        Queue<int,int> queue;
        for (int j = 0; j < maxSize; j++) {
            queue.Insert(j,0);
        }
        int l=getRandomInt(maxSize/2);
        auto *subQueue = queue.SubSequence(l, l*2);

        if (!queue.FindSubSequence(*subQueue)) {
            delete subQueue;
            continue;
        }

        subQueue->Insert(maxVal + 20,0);

        if (!queue.FindSubSequence(*subQueue))
            passed++;

        delete subQueue;
    }

    if (debug)
        debugPrint(count, passed);
}