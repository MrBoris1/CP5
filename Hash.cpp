#include <iostream>
#include <stdlib.h>
#include "Hash.h"
using namespace std;

Hash::Hash(){
    this->capacity=83;
    this->size=0;
}

PlayerNode* Hash::find(string name){
    int index = hashcaller(name);
    while(array[index].get_nu()){
        if(array[index].get_p().get_name()==name){
            return &(array[index]);
        }
        index++;
        index%=capacity;
    }
    return nullptr;
}

PlayerNode Hash::at(int i){
    return array[i];
}

PlayerNode Hash::aat(int i){
    return *parray[i];
}

PlayerNode* Hash::paat(int i){
    return parray[i];
}

void Hash :: insert(PlayerNode pl){
    int index = hashcaller(pl.get_p().get_name());
    while(array[index].get_nu()){
        index++;
        index%=capacity;
    }
    pl.set_at(index);
    array[index] = pl;
    size++;
    parray.push_back(&(array[index]));
}

int Hash::hashcaller(string name){
    int sum = 0;
    // cout << "Name: "<< name << endl;
    for(char i:name){
        sum+= int(i);
    }
    // cout << "Sum of the name: "<<sum<< " ,mod: "<< sum%capacity<< "\n"<<endl;
    return sum%capacity;
}

int Hash::get_size(){
    return size;
}

int Hash::get_capacity(){
    return capacity;
}

void Hash :: BFS(PlayerNode* p){
    for(int i=0; i<get_size();i++){
        parray[i]->set_color("White");
        parray[i]->set_dis(-1);
        p->set_prev(nullptr);
    }
    p->set_color("Gray");
    p->set_dis(0);
    p->set_prev(nullptr);
    vector<PlayerNode*>pl;
    pl.push_back(p);
    while(pl.size()>0){
        PlayerNode* t = pl.front();
        //cout << t->get_p().get_name()<<endl;
        pl.erase(pl.begin());
        // t->get_bb()->inorderPrint();
        t->get_bb()->BF(pl);
        t->set_color("Black");

    }
        
}
