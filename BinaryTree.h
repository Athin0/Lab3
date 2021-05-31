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
Node();
        Node(T data): data(data){};

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

        root = root->balance();
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
        GetStr(node->right);
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

public:

    BinaryTree() {
        root = nullptr;
    }

    explicit BinaryTree(ArraySequence<T>& arraySequence) {
        root = nullptr;
        for(int i = 0; i < arraySequence.GetLength(); i++)
            Insert(arraySequence[i]);
    }

    explicit BinaryTree(T item) {
        root = new Node(item);
    }

    BinaryTree(T *arr,int len) {
        root = nullptr;
        for(int i = 0; i < len; i++)
            Insert(i[arr]);
    }

    ~BinaryTree(){

        root=DeleteNode(root);
    }
    void Insert(T item){
        root= Insert(root, item);
    }
    void Remove(T item){
        root = Remove(root,item);
    }
    std::string GetStr(){
        auto res = GetStr(root, 0);
        res += '\n';
        return res;
    }
    void Find(T item){
        Find(root,item);
    }

};

template<class T>
std::ostream &operator<<(std::ostream &cout, BinaryTree<T> binaryTree) {
    cout << binaryTree.GetStr();
    return cout;
}

#endif //LAB3_BINARYTREE_H
