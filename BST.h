#ifndef BST_H
#define BST_H
#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

template <class T> 
class BST {
    struct node {
        T *data;
        node *left;
        node *right;   
    };
    
    node* root = NULL;
    unsigned int size;

    public:
        BST();
        ~BST();
        void insert(T *x);
	    void remove(string data); 
        T* search(string data);
        void inorderPrint();
        void inorderPrintHelper(struct node *&node);
        void destroy(struct node *&node);
        void BF(vector<T*> &vec,T*& t);
        void BFHelper(struct node *&root,struct node *&node,vector<T*> &vec, T*& t);
};
#include "BST.cpp"
#endif

