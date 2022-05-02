#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include "Player.h"
#include "Parser.h"

using namespace std;

int main(int argc, char** argv){
    
    ifstream inputfile;
    int opt,pind;
    string line;
    string te ="";
    string da ="";
    string sa ="";
    string in ="";
    vector<Player> play;
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
                // cout << sa << endl;
                break;
            case 'd':
                da = optarg;
                while (optind < argc && argv[optind][0] != '-') {
                    da = da + " "+argv[optind];
                    optind++;
                }
                // cout << da << endl;
                break;
            case 't':
                te = optarg;
                while (optind < argc && argv[optind][0] != '-') {
                    te = te + " "+argv[optind];
                    optind++;
                }
                // cout << te << endl;
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
            play.push_back(Player(command.getArg1(),command.getArg3(),command.getArg2()));
        }  
    }
    else{cout<<"File not found"<<endl;}
    inputfile.close();
    
    if(in != "" && da == "" && sa == "" && te == ""){
        int i=0;
        while(i<(int)play.size()){cout<<play[i].get_name()<<","<<play[i].get_team() <<","<<play[i].get_year() <<endl; i++;}
    }

    if(in != "" && da == "" && sa != "" && te == ""){
        sort(play.begin(), play.end());
        int i=0;
        while(i<(int)play.size()){
            if(play[i].get_name() == sa){
                cout<<play[i].get_name()<<" played for the "<<play[i].get_year() <<" "<<play[i].get_team() <<endl; 
            }
            i++;
        }
    }

    if(in != "" && da == "" && sa != "" && te != ""){
        sort(play.begin(), play.end());
        int i=0;
        while(i<(int)play.size()){
            if(play[i].get_name() == sa && play[i].get_team() == te){
                cout<<play[i].get_name()<<" played for the "<<play[i].get_year() <<" "<<play[i].get_team() <<endl; 
            }
            i++;
        }
    }
    // cout << "Sorted: "<<endl;
    // int i=0;
    // while(i<(int)play.size()){cout<<play[i].get_name()<<","<<play[i].get_team() <<","<<play[i].get_year() <<endl; i++;}
}

