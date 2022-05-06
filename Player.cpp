#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
using namespace std;

Player::Player(string name,string year,string team){
    this->name=name;
    this->year=year;
    this->team=team;
    this->count=1;
}

Player::Player(){
    this->name="";
    this->year="";
    this->team="";
    this->count=0;
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

int Player::get_count(){
    return this->count;
}

void Player::set_count(){
    this->count=1;
}

void Player::inc_count(){
    this->count+=1;
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