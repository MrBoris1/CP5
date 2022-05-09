#ifndef BST_H
#define BST_H
#include<iostream>
#include<stdlib.h>

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
        void destroy(struct node *&node);
};
#include "BST.cpp"
#endif

