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

void PrintSorted(vector<PlayerNode>& v)
{
    for (int j = 0; j < (int)v.size(); ++j) {
        for (int i = 0; i < (int)v.size() - j - 1; ++i) {
            if (v[i].get_dis() < v[i + 1].get_dis() || (v[i].get_dis() == v[i + 1].get_dis() && (v[i].get_p().get_name() > v[i + 1].get_p().get_name()))) {
                PlayerNode tempObj = v[i];
                v[i] = v[i + 1];     
                v[i + 1] = tempObj;
            }
        }
    }
    for(int i=0; i<(int)v.size(); i++) cout<<v[i].get_p().get_name()<<" played "<<v[i].get_dis() <<" years for "<<v[i].get_p().get_team() <<endl;
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
            play.insert(PlayerNode(Player(command.getArg1(),command.getArg3(),command.getArg2())));
        }  
    }
    else{cout<<"File not found"<<endl;}
    inputfile.close();
    
    if(in != "" && da == "" && sa == "" && te == ""){
        int i=0;
        while(i<(play.get_size())) { cout<<play.at(i).get_p().get_name()<<","<<play.at(i).get_p().get_team() <<","<<play.at(i).get_p().get_year() <<endl; i++;}
    }

    if(in != "" && da == "" && sa != "" && te == ""){
        //sort(play.begin(), play.end());
        int i=0;
        while(i<play.get_size()){
            if(play.at(i).get_p().get_name() == sa){
                cout<<play.at(i).get_p().get_name()<<" played for the "<<play.at(i).get_p().get_year() <<" "<<play.at(i).get_p().get_team() <<endl; 
            }
            i++;
        }
    }

    if(in != "" && da == "" && sa != "" && te != ""){
        //sort(play.begin(), play.end());
        int i=0;
        while(i<play.get_size()){
            if(play.at(i).get_p().get_name() == sa && play.at(i).get_p().get_team() == te){
                cout<<play.at(i).get_p().get_name()<<" played for the "<<play.at(i).get_p().get_year() <<" "<<play.at(i).get_p().get_team() <<endl; 
            }
            i++;
        }
    }

    if(in != "" && da == "" && sa == "" && te != ""){
        vector<PlayerNode> p;
        bool flag = true;
        for(long int i=0; i<play.get_size();i++){
            flag = true;
            if (play.at(i).get_p().get_team() != te) continue;
            for(long int j=0; j<(int)p.size();j++){
                if(play.at(i).get_p().get_name() == p.at(j).get_p().get_name() && play.at(i).get_p().get_team() == p.at(j).get_p().get_team()) {p.at(j).inc_dis(); flag = false; break;}
            }
            if(flag){
                play.at(i).set_dis(1);
                p.push_back(play.at(i));
            }
        }
        PrintSorted(p);
    }

    //Casse 4 will be done

}

