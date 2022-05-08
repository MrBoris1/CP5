#include <iostream>
#include <stdlib.h>
#include "Hash.h"
using namespace std;

Hash::Hash(){
    this-> capacity=83;
    this->size=0;
}

PlayerNode Hash::find(string name){
    int index = hashcaller(name);
    while(array[index].get_dis()!=-1){
        if(array[index].get_p().get_name()==name){
            return array[index];
        }
        index++;
        index%=capacity;
    }
    return PlayerNode();
}

PlayerNode Hash::at(int i){
    return array[i];
}

void Hash :: insert(PlayerNode pl){
    int index = hashcaller(pl.get_p().get_name());
    while(array[index].get_dis()!=-1){
        index++;
        index%=capacity;
    }
    array[index] = pl;
    size++;
}

int Hash::hashcaller(string name){
    int sum;
    for(char i:name){
        sum+=(int)i;
    }
    return sum%capacity;
}

int Hash::get_size(){
    return size;
}
