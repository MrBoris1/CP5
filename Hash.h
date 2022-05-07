#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class Hash{
    public:
        Hash(int capacity);
        Hash();
        int hashcaller(string name);
        Playernode* find(string name);
        void insert(Playernode pl);
    private:
        int capacity;
        int size;
        Playernode array[capacity];
};
