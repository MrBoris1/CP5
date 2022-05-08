#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "PlayerNode.h"
using namespace std;

PlayerNode::PlayerNode(Player p){
    this->p=p;
    dis=0;
    prev=nullptr;
}

PlayerNode::PlayerNode(){
    this->p=Player();
    dis=-1;
    at=-1;
    prev=nullptr;
}

Player PlayerNode::get_p(){
    return p;
}

void PlayerNode :: set_at(int i){ at= i;}
int PlayerNode :: get_at(){ return at;}

void PlayerNode::set_dis(int i){
    this->dis=i;
}

void PlayerNode::inc_dis(){
    this->dis+=1;
}

string PlayerNode::get_color(){
    return this->color;
}

int PlayerNode::get_dis(){
    return this->dis;
}

Player* PlayerNode::get_prev(){
    return this->prev;
}

BST<PlayerNode>* PlayerNode::get_bb(){
    return &bb;
}