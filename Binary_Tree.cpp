#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
Binary_Tree<T>::Binary_Tree(T data){
    this->data = data;
    this->r = NULL;
    this->l = NULL;
}

template <typename T>
Binary_Tree<T>::Binary_Tree(){
    this->r = NULL;
    this->l = NULL;
}

template <typename T>
T Binary_Tree<T>::get_data(){
    return this->data;
}

template <typename T>
void Binary_Tree<T>::set_data(T data){
    this->data = data;
}

template <typename T>
int Binary_Tree<T>::size_of_Tree(Binary_Tree *root){
    if(root == NULL)return 0;
    else{
        int count = 1;   
        count += size_of_Tree(root->l);                                     
        count += size_of_Tree(root->r);                                     
        return count;  
    }
}

template<typename T>
void Binary_Tree<T>::insert(Binary_Tree *&root, T data) {
    if ( root == NULL ) {
        root = new Binary_Tree<T>(data);
        return;
    }
    else if ( data < root->get_data() ) {
        insert(root->l, data);
    }
    else {
        insert( root->r, data);
    }
}  

template<typename T>
void Binary_Tree<T>::inorderPrint(Binary_Tree *root) {
    if ( root != NULL ) { 
        inorderPrint( root->l );  
        cout << root->get_data() << " ";    
        inorderPrint( root->r);   
    }
}

template<typename T>
Binary_Tree<T>* Binary_Tree<T>::Search(Binary_Tree *root, T item ) {
    if ( root == NULL ) {return NULL;}
    else if ( item == root->get_data() ) {return root;}
    else if ( item < root->get_data() ) {return Search( root->l, item);}
    else { return Search( root->r, item);}
}

template<typename T>
bool Binary_Tree<T>::Find(Binary_Tree *root, T item ) {
    if ( root == NULL ) {return false;}
    else if ( item == root->get_data() ) {return true;}
    else if ( item < root->get_data() ) {return Search( root->l, item);}
    else { return Search( root->r, item);}
}

template<typename T>
bool Binary_Tree<T>::remove(Binary_Tree *&tree, T data){
    Binary_Tree<T>* parent = NULL;
    Binary_Tree<T>* current = tree;
    while (current != NULL) {
        if (current->get_data() == data) {
            if (current->l == NULL && current->r == NULL) { 
                if (parent == NULL) {tree = NULL;}
                else if (parent->l == current) {parent->l = NULL;}
                else {parent->r = NULL;}
                delete current;
            }
            else if (current->r == NULL) {            
                if (parent == NULL) {tree = current->l;}
                else if (parent->l == current) {parent->l = current->l;}
                else {parent->r = current->l;}
                delete current;
            }
            else if (current->l == NULL) {           
                if (parent == NULL) {tree = current->r;}
                else if (parent->l == current) {parent->l = current->r;}
                else {parent->r = current->r;}
                delete current;
            }
            else {   
                Binary_Tree<T>* successor = current->r;
                while (successor->l != NULL){
                    successor = successor->l;
                }   
                T successorData = successor->get_data();
                remove(tree, successor->get_data());    
                current->set_data(successorData);
            }
            return true;
        }
        else if (current->get_data() < data) { 
            parent = current;
            current = current->r;
        }
        else {                     
            parent = current;
            current = current->l;
        }
    }
    return false;
}

template<typename T>
void Binary_Tree<T>::DestroyRecursive(Binary_Tree *&root)
{
    if (root != nullptr)
    {
        DestroyRecursive(root->l);
        DestroyRecursive(root->r);
        delete root;
    }
    return;
}
