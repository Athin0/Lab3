//
// Created by arina on 27.05.2021.
//

#ifndef LAB3_BINARYTREE_H
#define LAB3_BINARYTREE_H

#include <iostream>
#include "DynamicArraySequence.h"

template<class T>
class BinaryTree {
private:
    struct Node {
        T data;
        int height = 1;
        Node *left= nullptr;
        Node *right= nullptr;
        explicit Node(T data): data(data){};

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

        Node* rotateLeft() {
            Node *res = right;
            right = res->left;
            res->left = this;
            updateHeight();
            res->updateHeight();

            return res;
        }

        Node* rotateRight() {
            Node *res = left;
            left = res->right;
            res->right = this;
            updateHeight();
            res->updateHeight();

            return res;
        }

        Node* balance() {
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

    Node* DeleteNode(Node* node) {
        if(node == nullptr)
            return nullptr;
        {
            DeleteNode(node->left);
            DeleteNode(node->right);
            delete node;
        }
        return nullptr;
    }

    Node* Insert(Node* node, T x){
        if( node== nullptr){
            node =new Node(x);
            return node;
        }

        else if (x< node->data)
            node->left= Insert(node->left, x);
        else if(x>node->data)
            node->right= Insert(node->right, x);

        node->updateHeight();
        int delta = node->getDelta();

        if (delta <= 1 && delta >= -1) {
            return node;
        }
        node = node->balance();
        return node;

    }

    Node* FindMin(Node* node){
        if(node == nullptr)
            return nullptr;
        if(node->left == nullptr)
            return node;
        else
            return FindMin(node->left);
    }
    Node* FindMax(Node* node){
        if( node == nullptr)
            return nullptr;
        if (node->right== nullptr)
            return node;
        else
            return FindMax(node->right);
    }

    Node* Remove(Node* node,T x){
        Node* temp;
        if(node== nullptr)
            return nullptr;
        else if (x< node->data){
            node->left =Remove(node->left,x);
        }
        else if (x> node->data){
            node->right =Remove(node->right,x);
        }
        else if (node->left && node->right){
            temp= FindMin(node->right);
            node->data= temp->data;
            node->right = Remove(node->right,node->data);
        }
        else{
            temp=node;
            if (node->left== nullptr)
                node=node->right;
            else if(node->right== nullptr)
                node=node->left;
            delete temp;
        }

        node= node->balance();
        return node;
    }
/*
    void Print(Node *node) {
        if(node == nullptr)
            return;
        Print(node->left);
        std::cout<<"/ \t";
        std::cout << node->data << " ";
        std::cout<<"\t|";
        GetStrGreatTree(node->right);
        std::cout<<"\n";
    }
*/


    std::string GetStr(Node* p,int level)
    {
        if (!p)
            return std::string();

        std::string res;
        res += GetStr(p->right, level + 1);
        for(int i = 0;i < level;i++)
            res += "     ";

        res += std::to_string(p->data);
        res += '\n';
        res += GetStr(p->left, level + 1);

        return res;
    }
    Node* Find(Node* node,T data){
        if (node == nullptr){
            return nullptr;
        }
        else if (data<node->data)
            return Find(node->left,data);
        else if (data>node->data)
            return Find(node->right,data);
        else
            return node;
    };

    void InsertNode(Node* node) {
        if(node== nullptr){
            return;
        }
        Insert(node->data);
        InsertNode(node->left);
        InsertNode(node->right);
    }
    bool FindSubTree(Node* node, Node* nodeFind) {
        if(nodeFind== nullptr)
            return true;
        if (node== nullptr)
            return false;
        if(node->data != nodeFind->data)
            return false;
        return FindSubTree(node->left,nodeFind->left)&&
               FindSubTree(node->right,nodeFind->right);
    }

    void In_Str(Node* ptr, ArraySequence<T>* res, int First, int Second, int Third)
    { //Left=1 Root=2 Right=3
        if(ptr==nullptr)
            return;
        switch (First)
        {
            default:
                break;
            case 1:
                In_Str(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->data);
                break;
            case 3:
                In_Str(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Second)
        {
            default:
                break;
            case 1:
                In_Str(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->data);
                break;
            case 3:
                In_Str(ptr->right, res, First, Second, Third);
                break;
        }
        switch (Third)
        {
            default:
                break;
            case 1:
                In_Str(ptr->left, res, First, Second, Third);
                break;
            case 2:
                res->Append(ptr->data);
                break;
            case 3:
                In_Str(ptr->right, res, First, Second, Third);
                break;
        }
    }

public:

    BinaryTree() {
        root = nullptr;
    }

    explicit BinaryTree(ArraySequence<T>& arraySequence) {
        root = nullptr;
        for(int i = 0; i < arraySequence.GetLength(); i++)
            Insert(arraySequence[i]);
    }

    BinaryTree(const BinaryTree<T>& binaryTree) {
        root = nullptr;
        InsertNode(binaryTree.root);
    }

    explicit BinaryTree(T item) {
        root = new Node(item);
    }

    BinaryTree(T *arr,int len) {             //TODO самый важный конструкор
        root = nullptr;
        for(int i = 0; i < len; i++)
            Insert(i[arr]);
    }

    ~BinaryTree(){
        DeleteNode(root);
    }
    void Insert(T item){
        root= Insert(root, item);
    }
    void Remove(T item){
        root = Remove(root,item);
    }
    std::string GetStrGreatTree(){
        auto res = std::string("\n") + GetStr(root, 0);
        res += '\n';
        return res;
    }
    bool Find(T item){
        return Find(root,item);
    }
    BinaryTree* SubTree(T item){
        auto* node = Find(root,item);
        BinaryTree<T> tree;
        tree.root = node;
        auto *res = new BinaryTree<T>(tree);
        tree.root = nullptr;
        return res;
    }
    bool FindSubTree(const BinaryTree<T>& binaryTree) {
        if(binaryTree.root == nullptr)
            return true;

        auto *node = Find(root, binaryTree.root->data);
        if(node== nullptr)
            return false;
        else
            return true;
    }

    std::string In_Str(int First, int Second, int Third) {
        auto *resArr = new ArraySequence<T>;
        In_Str(root,resArr,First,Second,Third);
        std::string resStr("{");
        for (int i = 0; i < resArr->GetLength(); i++) {
            resStr+=std::to_string(resArr->Get(i));
            if(i!=resArr->GetLength()-1)
                resStr+=", ";
        }
        resStr+="}";
        delete resArr;
        return resStr;
    }

    BinaryTree* Map(T(*func)(T, T), T elem)
    {
        ArraySequence<T> arr;
        In_Str(root,&arr,1,2,3);
        auto *resArr = arr.Map(func, elem);
        auto* res=new BinaryTree<T>(*resArr);
        delete resArr;
        return res;
    }

    BinaryTree* Map(T(*func)(T))
    {
        ArraySequence<T> arr;
        In_Str(root,&arr,1,2,3);
        auto *resArr = arr.Map(func);
        auto* res=new BinaryTree<T>(*resArr);
        delete resArr;
        return res;
    }

    BinaryTree* Map(T(*func)(void))
    {
        ArraySequence<T> arr;
        In_Str(root,&arr,1,2,3);
        arr.Map(func);
        auto* res=new BinaryTree<T>(arr);
        return res;
    }

    BinaryTree* Where(bool(*func)(T))
    {
        ArraySequence<T> arr;
        In_Str(root,&arr,1,2,3);
        auto *resArr = arr.Where(func);
        auto* res = new BinaryTree<T>(*resArr);
        delete resArr;
        return res;
    }

    T Reduce(T(*func)(T, T), T item)
    {
        ArraySequence<T> arr;
        In_Str(root,&arr,1,2,3);
        T res = arr.Reduce(func, item);
        return res;
    }

    ArraySequence<T>* GetValues(){
        auto *arrRes= new ArraySequence<T>;
        In_Str(root, arrRes, 1, 2, 3);
        return arrRes;
    }
};

template<class T>
std::ostream &operator<<(std::ostream &cout, BinaryTree<T> binaryTree) {
    cout << binaryTree.GetStrGreatTree();
    return cout;
}

#endif //LAB3_BINARYTREE_H
