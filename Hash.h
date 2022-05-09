#pragma once
#include <iostream>
#include <stdlib.h>
#include "PlayerNode.h"
using namespace std;

class Hash{
    public:
        Hash();
        int hashcaller(string name);
        PlayerNode find(string name);
        PlayerNode at(int i);
        PlayerNode aat(int i);
        PlayerNode* paat(int i);
        void insert(PlayerNode pl);
        int get_size();
        int get_capacity();
        void BFS(PlayerNode* p);
    private:
        int capacity;
        int size;
        PlayerNode array[83];
        vector<PlayerNode*> parray;
};
