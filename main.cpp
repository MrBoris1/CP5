#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include "Parser.h"
#include "Hash.h"

using namespace std;

void PrintSorted(vector<PlayerNode*>& v,int c){
    switch(c){
    case 1:
        for (int j = 0; j < (int)v.size(); ++j) {
            for (int i = 0; i < (int)v.size() - j - 1; ++i) {
                if (v[i]->get_p().get_year()>v[i]->get_p().get_year()){
                    PlayerNode* tempObj = v[i];
                    v[i] = v[i + 1];     
                    v[i + 1] = tempObj;
                }
            }
        }
        for(int i=0; i<(int)v.size(); i++) cout<<v[i]->get_p().get_name()<<" played for the "<< v[i]->get_p().get_year()<<" "<<v[i]->get_p().get_team() <<endl;
        break;
    case 2:
        for (int j = 0; j < (int)v.size(); ++j) {
            for (int i = 0; i < (int)v.size() - j - 1; ++i) {
                if (v[i]->get_dis() < v[i + 1]->get_dis() || (v[i]->get_dis() == v[i + 1]->get_dis() && (v[i]->get_p().get_name() > v[i + 1]->get_p().get_name()))) {
                    PlayerNode* tempObj = v[i];
                    v[i] = v[i + 1];     
                    v[i + 1] = tempObj;
                }
            }
        }
        for(int i=0; i<(int)v.size(); i++) {cout<<v[i]->get_p().get_name()<<" played "<<v[i]->get_dis() <<" years for "<<v[i]->get_p().get_team() <<endl;}
    }
}



int main(int argc, char** argv){
    
    ifstream inputfile;
    int opt,pind;
    string line;
    string te ="";
    string da ="";
    string sa ="";
    string in ="";
    Hash play;
    Player t;

    while(pind = optind, (opt=getopt(argc, argv, "i:s:d:t:"))!=-1){
        if (optind == pind + 2 && *optarg == '-'){
            opt = 'a';
            -- optind;
        }
        switch(opt){
            case 'i':
                in = optarg;
                break;
            case 's':
                sa = optarg;
                while (optind < argc && argv[optind][0] != '-') {
                    sa = sa + " "+argv[optind];
                    optind++;
                }
                break;
            case 'd':
                da = optarg;
                while (optind < argc && argv[optind][0] != '-') {
                    da = da + " "+argv[optind];
                    optind++;
                }
                break;
            case 't':
                te = optarg;
                while (optind < argc && argv[optind][0] != '-') {
                    te = te + " "+argv[optind];
                    optind++;
                }
                break;
            case '?':
                cout<< "Unknown command returns: "<<opt<<endl;
        }
    }
    if(in == ""){cout<<"Error: Input file not given!!!\n"; return 0;}
    if(da != "" && sa == ""){cout <<"Error: first player is not given!!!\n"; return 0;}
    
    inputfile.open(in);
    if(inputfile.is_open()){
        while(getline(inputfile, line)){
            Parser command(line);
            play.insert(PlayerNode(Player(command.getArg1(),command.getArg3(),command.getArg2())));
            
            for(int i=0; i<play.get_size()-1; i++){
                if(play.paat(i)->get_p().get_team()==play.paat(play.get_size()-1)->get_p().get_team() && play.paat(i)->get_p().get_year()==play.paat(play.get_size()-1)->get_p().get_year()){
                    play.paat(i)->get_bb()->insert(play.paat(play.get_size()-1));
                    play.paat(play.get_size()-1)->get_bb()->insert(play.paat(i));
                }
            }
            
        }
        for(int i=0; i<play.get_size()-1; i++){
            for(int j=0; j<play.get_size()-1; j++){
                if(play.paat(i)->get_p().get_name()==play.paat(j)->get_p().get_name() && play.paat(i)->get_p().get_year()!=play.paat(j)->get_p().get_year()){
                    //cout<< play.paat(i)->get_p().get_name()<< " "<<play.paat(j)->get_p().get_name()<<endl;
                    play.paat(j)->get_bb()->add(play.paat(i)->get_bb());
                }
            }
        }

          
    }
    else{cout<<"File not found"<<endl;}
    inputfile.close();
    
    if(in != "" && da == "" && sa == "" && te == ""){
        int i=0;
        while(i<(play.get_size())) {cout<<play.paat(i)->get_p().get_name()<<","<<play.paat(i)->get_p().get_team() <<","<<play.paat(i)->get_p().get_year() <<endl; i++;}
    }

    if(in != "" && da == "" && sa != "" && te == ""){
        vector<PlayerNode*> p;
        int i = 0;
        while(play.findN(sa,i)!=nullptr){
            PlayerNode* t = play.findN(sa,i);
            if (t == nullptr){break;}
            //cout << t->get_p().get_name()<< " count : "<<i<<endl;
            if(t->get_p().get_name()==sa) p.push_back(t);
            i++;
        }
        if(p.size()==0) cout<<sa<<" does not appear in the input file"<<endl;
        PrintSorted(p,1);
        
    }

    if(in != "" && da == "" && sa != "" && te != ""){
        vector<PlayerNode*> p;
        int i= 0;
        while(play.findN(sa,i)!=nullptr){
            PlayerNode* t = play.findN(sa,i);
            if (t == nullptr){break;}
            if(t->get_p().get_name()==sa && t->get_p().get_team()==te) p.push_back(t);
            i++;
        }
        if(p.size()==0) cout<<sa<<" has never played for the "<< te <<endl;
        PrintSorted(p,1);
    }

    if(in != "" && da == "" && sa == "" && te != ""){
        vector<PlayerNode*> p;
        bool flag = true;
        for(long int i=0; i<play.get_size();i++){
            flag = true;
            if (play.paat(i)->get_p().get_team() != te) continue;
            for(long int j=0; j<(int)p.size();j++){
                if(play.paat(i)->get_p().get_name() == p.at(j)->get_p().get_name() && play.paat(i)->get_p().get_team() == p.at(j)->get_p().get_team()) {p.at(j)->inc_dis(); flag = false; break;}
            }
            if(flag){
                p.push_back(play.paat(i));
                p.at(p.size()-1)->set_dis(1);
            }
        }
        PrintSorted(p,2);
    }


    if(in != "" && da != "" && sa != "" && te == ""){
        // for(int i=0; i<play.get_size();i++) play.paat(i)->get_bb()->inorderPrint();
        play.B(sa,da);

    }

    if(in != "" && da != "" && sa != "" && te != ""){
        play.B(sa,da,te);
        // Case 4B
    }
    //Case 4 will be done

    
}

