#pragma once
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Player.h"
using namespace std;
 

class Graph{
    
    int Vertices;   
    vector<vector<Player>> adj;

    public:
        Graph(int Vertices);
        void addEdge(int v, int w);
        void BFS(int s); 
};