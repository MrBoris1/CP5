#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
using namespace std;

Player::Player(string name,string year,string team){
    this->name=name;
    this->year=year;
    this->team=team;
}

Player::Player(){
    this->name="";
    this->year="";
    this->team="";
}


string Player::get_name(){
    return this->name;
}

string Player::get_year(){
    return this->year;
}

string Player::get_team(){
    return this->team;
}

bool Player::operator==(Player &other){
    if(this->name == other.get_name() && this->year == other.get_year() && this->team == other.get_team()){
        return true;
    }
    return false;
}

bool Player::operator<(Player &other){
    if(this->year < other.get_year()){
        return true;
    }
    return false;
}

bool Player::operator>(Player &other){
    if(this->year > other.get_year()){
        return true;
    }
    return false;
}