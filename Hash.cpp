#include <iostream>
#include <stdlib.h>
#include "Hash.h"
using namespace std;

Hash::Hash(int capacity){
    this-> capacity=capacity;
    this->size=0;
}

Playernode* Hash::find(string name){
    //Ayberk pp small
    int index = hashcaller(name);
    while(array[index]!=NULL){
        if(array[index].get_name()==name){
            return &array[index];
        }
        index++;
        index%=capacity;
    }
    return nullptr;
}

void insert(Playernode &pl){
    int index = hashcaller(pl.get_name());
    while(array[index]!=NULL){
        index++;
        index%=capacity;
    }
    array[index] = pl;
}

int Hash::hashcaller(string name){
    int sum;
    for(char i:name){
        sum+=(int)i;
    }
    return sum%capacity;
}