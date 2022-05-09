#pragma once
#include <iostream>
#include <stdlib.h>
#include"Player.h"
#include "BST.h"
using namespace std;

class PlayerNode{
    private:
        Player p;
        string color;
        int dis;
        int at;
        PlayerNode* prev;
        BST<PlayerNode> bb;
    
    public:
        PlayerNode(Player p);
        PlayerNode();
        void set_at(int i);
        int get_at();
        Player get_p();
        void set_dis(int i);
        void inc_dis();
        bool operator==(Player &other);
        bool operator<(Player &other);
        bool operator>(Player &other);
        string get_color();
        void set_color(string s);
        void set_prev(PlayerNode* p);
        int get_dis();
        PlayerNode* get_prev();
        BST<PlayerNode>* get_bb();
        void printPath();
};