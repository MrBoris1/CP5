#pragma once
#include <iostream>

class Playenode{
    public:
        Playernode();
        Player* get_po();
        string get_color();
        int get_dis();
        Player* get_prev();
        Binary_Tree<Player> get_bb();
    private:
        Player* po;
        string color;
        int dis;
        Player* prev;
        Binary_Tree<Player> bb;        
};