#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
using namespace std;


Graph::Graph(int Vertices)
{
    this->Vertices = V;
    adj.resize(Vertices);
}
 
void Graph::addEdge(int vertices, Player w)
{
    adj[vertices].push_back(w); 
}
 
void Graph::BFS(int s)
{
    return;
}