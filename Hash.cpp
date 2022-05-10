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

void Hash::B(string f,string s, string str){
    int index = hashcaller(f);
    int dist= capacity;
    PlayerNode* shrt;
    while(array[index].get_nu()){
        if(array[index].get_p().get_name()==f){
            int index2 = hashcaller(s);
            while(array[index2].get_nu()){
                //cout <<"Out side: "<< array[index2].get_p().get_team()<<" "<< array[index2].get_p().get_year()<<endl;
                if(array[index2].get_p().get_name()==s){
                    //cout << "In loop: "<<array[index].get_p().get_team()<< " "<< array[index].get_p().get_year()<<" --> "<<array[index2].get_p().get_team()<< " "<< array[index2].get_p().get_year()<<endl;
                    PlayerNode* p=&(array[index]);
                    BFS(p, str);
                    if(array[index2].get_dis()!=-1 && array[index2].get_dis()< dist) {dist= array[index2].get_dis();shrt= &(array[index2]); }
                }
                index2++;
                index2%=capacity;
            }
            
        }
        index++;
        index%=capacity;
    }
    if(!(shrt->get_prev()==nullptr)) {shrt->printPath(); return;}
    else{cout<<"No teammate path exists between "<< f<<" and "<< s <<endl;}
}

PlayerNode* Hash::at(int i){
    return &(array[i]);
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

    array[index] = pl;
    size++;
    pl.set_at(index);
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

void Hash :: BFS(PlayerNode* p, string str){
    for(int i=0; i<get_size();i++){
        parray[i]->set_color("White");
        parray[i]->set_dis(-1);
        p->set_prev(nullptr);
    }
    p->set_color("Gray");
    p->set_dis(0);
    vector<PlayerNode*>pl;
    pl.push_back(p);
    while(pl.size()>0){
        PlayerNode* t = pl.front();
        pl.erase(pl.begin());
        t->get_bb()->BF(pl,t, str);
        t->set_color("Black");
    }
        
}

PlayerNode* Hash::findN(string name,int i){
    int x=0;
    int index = hashcaller(name);
    while(array[index].get_nu()){
        if(array[index].get_p().get_name()==name){
            if (x==i) return &(array[index]);
            x++;
        }
        index++;
        index%=capacity;
    }
    return nullptr;
}