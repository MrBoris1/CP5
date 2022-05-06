#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class Player{
    private:
        string name;
        string year;
        string team;
        int count;
    public:
        Player(string name,string year,string team);
        Player();
        string get_name();
        string get_year();
        string get_team();
        int get_count();
        void set_count();
        void inc_count();
        bool operator==(Player &other);
        bool operator<(Player &other);
        bool operator>(Player &other);
};