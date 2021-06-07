//
// Created by arina on 27.05.2021.
//

#ifndef LAB3_BINARYTREE_H
#define LAB3_BINARYTREE_H

#include <iostream>
#include "DynamicArraySequence.h"

template<class T, class K>
class BinaryTree {
private:
    struct Node {
        T key;
        K value;
        int height = 1;
        Node *left = nullptr;
        Node *right = nullptr;

        explicit Node(T data, K val) : key(data), value(val) {};

        explicit Node(T data) : key(data) {};
        T GetValue() {
            return value;
        }

        int getDelta() {
            auto h1 = left == nullptr ? 0 : left->height;
            auto h2 = right == nullptr ? 0 : right->height;
            return h2 - h1;
        }

        void updateHeight() {
            int h1 = left == nullptr ? 0 : left->height;
            int h2 = right == nullptr ? 0 : right->height;
            height = (h1 > h2 ? h1 : h2) + 1;
        }

        Node *rotateLeft() {
            Node *res = right;
            right = res->left;
            res->left = this;
            updateHeight();
            res->updateHeight();

            return res;
        }

        Node *rotateRight() {
            Node *res = left;
            left = res->right;
            res->right = this;
            updateHeight();
            res->updateHeight();

            return res;
        }

        Node *balance() {
            updateHeight();
            auto delta = getDelta();
            if (delta < -1) {
                if (left != nullptr && left->getDelta() > 0)
                    left = left->rotateLeft();
                return rotateRight();
            }
            if (delta > 1) {
                if (right != nullptr && right->getDelta() < 0)
                    right = right->rotateRight();
                return rotateLeft();
            }
            return this;
        }
    };


    Node *root;

    Node *DeleteNode(Node *node) {
        if (node == nullptr)
            return nullptr;
        {
            DeleteNode(node->left);
            DeleteNode(node->right);
            delete node;
        }
        return nullptr;
    }

    Node *InsertNonBalance(Node *node, T x, K val) {
        if (node == nullptr) {
            node = new Node(x, val);
            return node;
        } else if (x < node->key)
            node->left = InsertNonBalance(node->left, x, val);
        else if (x > node->key)
            node->right = InsertNonBalance(node->right, x, val);

        return node;
    }

    Node *Insert(Node *node, T x, K val) {
        if (node == nullptr) {
            node = new Node(x, val);
            return node;
        } else if (x < node->key)
            node->left = Insert(node->left, x, val);
        else if (x > node->key)
            node->right = Insert(node->right, x, val);

        node->updateHeight();
        int delta = node->getDelta();

        if (delta <= 1 && delta >= -1) {
            return node;
        }
        node = node->balance();
        return node;

    }

    Node *FindMin(Node *node) {
        if (node == nullptr)
            return nullptr;
        if (node->left == nullptr)
            return node;
        else
            return FindMin(node->left);
    }

    Node *FindMax(Node *node) {
        if (node == nullptr)
            return nullptr;
        if (node->right == nullptr)
            return node;
        else
            return FindMax(node->right);
    }

    Node *Remove(Node *node, T x) {
        Node *temp;
        if (node == nullptr)
            return nullptr;
        else if (x < node->key) {
            node->left = Remove(node->left, x);
        } else if (x > node->key) {
            node->right = Remove(node->right, x);
        } else if (node->left && node->right) {
            temp = FindMin(node->right);
            node->key = temp->key;
            node->right = Remove(node->right, node->key);
        } else {
            temp = node;
            if (node->left == nullptr)
                node = node->right;
            else if (node->right == nullptr)
                node = node->left;
            delete temp;
        }
        return node;
    }

/*
    void Print(Node *node) {
        if(node == nullptr)
            return;
        Print(node->left);
        std::cout<<"/ \t";
        std::cout << node->key << " ";
        std::cout<<"\t|";
        GetStrGreatTree(node->right);
        std::cout<<"\n";
    }
*/


    std::string GetStrKey(Node *p, int level) const {
        if (!p)
            return std::string();

        std::string res;
        res += GetStrKey(p->right, level + 1);
        for (int i = 0; i < level; i++)
            res += "     ";

        res += std::to_string(p->key);
        res += '\n';
        res += GetStrKey(p->left, level + 1);

        return res;
    }
    std::string GetStrKeyAndValue(Node *p, int level) const {
        if (!p)
            return std::string();

        std::string res;
        res += GetStrKeyAndValue(p->right, level + 1);
        for (int i = 0; i < level; i++)
            res += "           ";
        res += std::to_string(p->key);
        res += "--";
        res += std::to_string(p->value);
        res += '\n';
        res += GetStrKeyAndValue(p->left, level + 1);

        return res;
    }

    Node *FindNode(Node *node, T data) {
        if (node == nullptr) {
            return nullptr;
        } else if (data < node->key)
            return FindNode(node->left, data);
        else if (data > node->key)
            return FindNode(node->right, data);
        else
            return node;
    };

    void InsertNode(Node *node) {
        if (node == nullptr) {
            return;
        }
        root = InsertNonBalance(root, node->key, node->value);
        InsertNode(node->left);
        InsertNode(node->right);
    }

    bool FindSubTree(Node *node, Node *nodeFind) {
        if (nodeFind == nullptr)
            return true;
        if (node == nullptr)
            return false;
        if (node->key != nodeFind->key)
            return false;
        return FindSubTree(node->left, nodeFind->left) &&
               FindSubTree(node->right, nodeFind->right);
    }

    void In_Str_Key(Node *ptr, ArraySequence<T> *res, int First, int Second, int Third) { //Left=1 Root=2 Right=3
        if (ptr == nullptr)
            return;
        switch (First) {
            default:
                break;
            case 1:
                In_Str_Key(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->key);
                break;
            case 3:
                In_Str_Key(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Second) {
            default:
                break;
            case 1:
                In_Str_Key(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->key);
                break;
            case 3:
                In_Str_Key(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Third) {
            default:
                break;
            case 1:
                In_Str_Key(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->key);
                break;
            case 3:
                In_Str_Key(ptr->right, res, First, Second, Third);
                break;
        }
    }

    void In_Str_Val(Node *ptr, ArraySequence<T> *res, int First, int Second, int Third) {
        //Left=1 Root=2 Right=3
        if (ptr == nullptr)
            return;
        switch (First) {
            default:
                break;
            case 1:
                In_Str_Val(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->value);
                break;
            case 3:
                In_Str_Val(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Second) {
            default:
                break;
            case 1:
                In_Str_Val(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->value);
                break;
            case 3:
                In_Str_Val(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Third) {
            default:
                break;
            case 1:
                In_Str_Val(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->value);
                break;
            case 3:
                In_Str_Val(ptr->right, res, First, Second, Third);
                break;
        }
    }

    void MapNode(Node* node, T(*func)(T)){
        if (node == nullptr)
            return;
        MapNode(node->left, func);
        MapNode(node->right, func);
        node->value= func(node->value);
    }
    void MapNode(Node* node, T(*func)(void)){
        if (node == nullptr)
            return;
        MapNode(node->left, func);
        MapNode(node->right, func);
        node->value= func(node->value);
    }
    void MapNode(Node* node,T(*func)(T, T), T elem){
        if (node == nullptr)
            return;
        MapNode(node->left, func,elem);
        MapNode(node->right, func,elem);
        node->value= func(node->value,elem);
    }
    void WhereNode(Node* node, bool(func(K)),BinaryTree<T,K> &tree){
        if (node== nullptr)
            return;
        if (func(node->key)){
            tree.Insert(node->key,node->value);
        }
        WhereNode(node->left,func,tree);
        WhereNode(node->right,func,tree);
        return;
    }

public:

    BinaryTree() {
        root = nullptr;
    }

    explicit BinaryTree(ArraySequence<T> &arraySequence, ArraySequence<T> &valArr) {
        root = nullptr;
        for (int i = 0; i < arraySequence.GetLength(); i++)
            Insert(arraySequence[i], valArr[i]);
    }
     BinaryTree(ArraySequence<T> &arraySequence) {
        root = nullptr;
        for (int i = 0; i < arraySequence.GetLength(); i++)
            Insert(arraySequence[i], 0);
    }

    BinaryTree(const BinaryTree<T,K> &binaryTree) {
        root = nullptr;
        InsertNode(binaryTree.root);
    }

    explicit BinaryTree(T item) {
        root = new Node(item);
    }

    BinaryTree(T *arr,K *arrVal, int len) {                                                          // самый важный конструкор
        root = nullptr;
        for (int i = 0; i < len; i++)
            Insert(i[arr], i[arrVal]);
    }

    ~BinaryTree() {
        DeleteNode(root);
    }

    void Insert(T item, K val) {
        root = Insert(root, item, val);
    }

    void Remove(T item) {
        root = Remove(root, item);
        ArraySequence<T> arr;
        In_Str_Key(root, &arr, 1, 2, 3);
        auto *res = new BinaryTree<T, K>(arr);
        DeleteNode(root);
        root = res->root;
    }

    std::string GetStrGreatTree() const {
        auto res = std::string("\n") + GetStrKeyAndValue(root, 0);
        res += '\n';
        return res;
    }

    bool Find(T item) {
        return FindNode(root, item);
    }

    BinaryTree *SubTree(T item) {
        auto *node = FindNode(root, item);
//        BinaryTree<T, K> tree;
//        tree.root = node;
        auto *res = new BinaryTree<T, K>;
        res->InsertNode(node);
//        tree.root = nullptr;
        return res;
    }

    bool FindSubTree(const BinaryTree<T, K> &binaryTree) {
        if (binaryTree.root == nullptr)
            return true;

        auto *node = FindNode(root, binaryTree.root->key);
        return FindSubTree(node, binaryTree.root);

    }

    std::string In_Str(int First, int Second, int Third) {
        auto *resArr = new ArraySequence<T>;
        In_Str_Key(root, resArr, First, Second, Third);
        std::string resStr("{");
        for (int i = 0; i < resArr->GetLength(); i++) {
            resStr += std::to_string(resArr->Get(i));
            if (i != resArr->GetLength() - 1)
                resStr += ", ";
        }
        resStr += "}";
        delete resArr;
        return resStr;
    }


    BinaryTree *Map(T(*func)(T, T), T elem) {
        auto *res = new BinaryTree<T, K>(*this);
        MapNode(res->root, func,elem);
        return res;
    }
    BinaryTree *Map(T(*func)(T)) {
        auto *res = new BinaryTree<T, K>(*this);
        MapNode(res->root, func);
        return res;
    }
    BinaryTree *Map(T(*func)(void)) {
        auto *res = new BinaryTree<T, K>(*this);
        MapNode(res->root, func);
        return res;
    }

    K Reduce(K(*func)(K, K), K item) {
        ArraySequence<T> arrVal;
        In_Str_Val(root, &arrVal, 1, 2, 3);
        T res = arrVal.Reduce(func, item);
        return res;
    }

    BinaryTree *Where(bool(*func)(T)) {
        auto *res = new BinaryTree<T, K>();
        WhereNode(this->root, func,*res);
        return res;
    }


    ArraySequence<T> *GetKeyArray() {
        auto *arrRes = new ArraySequence<T>;
        In_Str_Key(root, arrRes, 1, 2, 3);
        return arrRes;
    }

    ArraySequence<T> *GetValuesArray() {
        auto *arrRes = new ArraySequence<T>;
        In_Str_Val(root, arrRes, 1, 2, 3);
        return arrRes;
    }

    BinaryTree<T, K> &operator=(const BinaryTree<T, K> &binaryTree) {
        DeleteNode(root);
        root = nullptr;
        InsertNode(binaryTree.root);
        return *this;
    }

    T GetValueKey(T key) {
        Node* node = FindNode(root, key);
        return node->GetValue();
    }

};

template<class T, class K>
std::ostream &operator<<(std::ostream &cout, const BinaryTree<T, K> &binaryTree) {
    cout << binaryTree.GetStrGreatTree();
    return cout;
}
/*
     BinaryTree *Map(T(*func)(T, T), T elem) {
        ArraySequence<T> arr;
        ArraySequence<T> arrVal;
        In_Str_Val(root, &arrVal, 1, 2, 3);
        In_Str_Val(root, &arr, 1, 2, 3);
        auto *resArr = arrVal.Map(func, elem);
        auto *res = new BinaryTree<T, K>(* arr, *resArr);
        delete resArr;
        return res;
    }
    BinaryTree *Map(T(*func)(T)) {
        ArraySequence<T> arr;
        ArraySequence<T> arrVal;
        In_Str_Val(root, &arrVal, 1, 2, 3);
        In_Str_Key(root, &arr, 1, 2, 3);
        auto *resArr = arrVal.Map(func);
        auto *res = new BinaryTree<T, K>(arr, *resArr);
        delete resArr;
        return res;

    }


    BinaryTree *Map(T(*func)(void)) {
        ArraySequence<T> arr;
        ArraySequence<T> arrVal;
        In_Str_Val(root, &arrVal, 1, 2, 3);
        In_Str_Key(root, &arr, 1, 2, 3);
        auto *resArr = arrVal.Map(func);
        auto *res = new BinaryTree<T, K>( arr, *resArr);
        delete resArr;
        return res;
    }

    BinaryTree *Where(bool(*func)(T)) {
        ArraySequence<T> arr;
        ArraySequence<T> arrVal;
        In_Str_Val(root, &arrVal, 1, 2, 3);
        In_Str_Key(root, &arr, 1, 2, 3);
        auto *resArr = arrVal.Where(func);
        auto *res = new BinaryTree<T, K>( arr, *resArr);
        delete resArr;
        return res;
    }
    */
#endif //LAB3_BINARYTREE_H
