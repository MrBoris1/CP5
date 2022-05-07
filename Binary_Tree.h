#ifndef Binary_Tree_H
#define Binary_Tree_H
#include <iostream>
#include <string.h>
using namespace std;

template<class T> class Binary_Tree{
    private:
        T data;
    public:
        Binary_Tree* l;
        Binary_Tree* r;
        T get_data();
        void set_data(T data);
        Binary_Tree(T data);
        Binary_Tree();
        int size_of_Tree(Binary_Tree *root);
        void insert(Binary_Tree *&root, T data);
        void inorderPrint( Binary_Tree *root );
        Binary_Tree* Search(Binary_Tree *root, T item);
        bool remove(Binary_Tree *&tree, T data);
        void DestroyRecursive(Binary_Tree *&root);
        bool Find(Binary_Tree *root, T item );
};
#include "Binary_Tree.cpp"

#endif