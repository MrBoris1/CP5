#include<iostream>
#include<stdlib.h>

using namespace std;
//binary search tree
template <typename T>
BST<T>::BST() {
    root = NULL;
}

template <typename T>
void BST<T>::insert(T *d){
	node* t = new node;
	node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	if(root == NULL) {root = t; }
	else
	{
		node* curr;
		curr = root;

		while(curr){
			parent = curr;
			if(t->data> curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if(t->data < parent->data) parent->left = t;
		else parent->right = t;
	}
}



template <typename T>
void BST<T>::remove(string d){
	node *par = NULL;
	node *curr = root;
	while(curr != NULL){
		if((curr->data).get_str() == d){
			if(curr->right == NULL && curr->left == NULL){
				if (par == NULL) root = NULL;
				else if (par->left == curr) par->left = NULL;
				else par->right = NULL;
				delete curr;
			}
			else if(curr->right == NULL){
				if (par == NULL) root = curr->left;
				else if (par->left == curr) par->left = curr->left;
				else par->right = curr->left;
				delete curr;
			}
			else if(curr->left == NULL){
				if (par == NULL) root = curr->right;
				else if (par->left == curr) par->left = curr->right;
				else par->right = curr->right;
				delete curr;
			}

			else{
				node* suc = curr->right;
				while(suc->left != NULL) {suc = suc->left;}
				T temp = suc->data;
				remove((suc->data).get_str());
				curr->data = temp;
			}
			return;
		}
		else if((curr->data).get_str() < d){
			par = curr;
			curr = curr->right;
			
		}
		else{
			par = curr;
			curr = curr->left;

		}
	}
	return;

}

template <typename T>
T* BST<T>::search(string d){
	node* curr;
	curr = root;
	while(curr != NULL){
		if((curr->data->get_p().get_name()) == d){
			return (curr->data);
		}
		else{
			if(d > curr->data->get_p().get_name()) curr = curr->right;
			else curr = curr->left;
		}
	}
	delete curr;
    return nullptr;
}

template <typename T>
void BST<T>::destroy(struct node *&node){
	if(node!=NULL){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

template<typename T>
void BST<T>::inorderPrint() {
	inorderPrintHelper(root);
	cout<<endl;
}

template<typename T>
void BST<T>::inorderPrintHelper(struct node *&node) {
    if ( node != NULL ) { 
        inorderPrintHelper( node->left );
		cout<< node->data->get_p().get_name()<<" ";
        inorderPrintHelper( node->right);   
    }
}

template <typename T>
BST<T>::~BST(){
	destroy(root);
}

template<typename T>
void BST<T>::BF(vector<T*> &vec, T*& t, string str) {
	node* curr;
	curr = root;
	BFHelper(root,curr,vec, t, str);
}

template<typename T>
void BST<T>::BFHelper(struct node *&root,struct node *&node, vector<T*> &vec, T*& t, string str) {
	if(node!=nullptr){
		
		if (node->left != nullptr) {BFHelper(root,node->left,vec, t, str);}
		if (str.size()>0){
			if(node->data->get_color()=="White" && node->data->get_p().get_team()== str){
				node->data->set_color("Gray");
				node->data->set_dis(t->get_dis()+1);
				node->data->set_prev(t);
				vec.push_back(node->data);
			}
		}
		else{
			if(node->data->get_color()=="White"){
				node->data->set_color("Gray");
				node->data->set_dis(t->get_dis()+1);
				node->data->set_prev(t);
				vec.push_back(node->data);
		}
		}
		if (node->right != nullptr) {BFHelper(root,node->right,vec, t, str);}
	}
}

template<typename T>
void BST<T>::add(BST<T> *x){
	addHelper(root,x);
}

template<typename T>
void BST<T>::addHelper(struct node *&root, BST<T> *x){
	if(root!=nullptr){
		addHelper(root->left,x);
		if (x->search(root->data->get_p().get_name()) == nullptr){x->insert(root->data);}
		addHelper(root->right,x);
	}
}



