#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "PlayerNode.h"
using namespace std;

PlayerNode::PlayerNode(Player p){
    this->p=p;
    dis=0;
    prev=nullptr;
    nu = 1;
}

PlayerNode::PlayerNode(){
    this->p=Player();
    dis=-1;
    at=-1;
    nu = 0;
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

PlayerNode* PlayerNode::get_prev(){
    return this->prev;
}

BST<PlayerNode>* PlayerNode::get_bb(){
    return &bb;
}

void PlayerNode::set_color(string s){
    color=s;
}
void PlayerNode::set_prev(PlayerNode* p){
    prev=p;
}

int PlayerNode::get_nu(){
    return nu;
}

void PlayerNode::printPath(){
    if(!prev->get_nu()) return;
    
    cout<<p.get_name()<<" played with"<< prev->get_p().get_name()<<" on the "<<p.get_year()<<" "<<p.get_team()<<endl;
    // prev->printPath();
}