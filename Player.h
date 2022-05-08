#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Player{
    private:
        string name;
        string year;
        string team;
        

    public:
        Player(string name,string year,string team);
        Player();
        string get_name();
        string get_year();
        string get_team();
        bool operator==(Player &other);
        bool operator<(Player &other);
        bool operator>(Player &other);
};