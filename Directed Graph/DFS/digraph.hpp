#include "digraph.h"
#include <list>
#include <iostream>
using namespace std; 

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add weights to v's list 
    adj[v].push_back(w); 
}

void Graph::recursiveDFS(int v, bool visited[])
{
    // Current node marked as visited
    visited[v] = true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    // Recursively reach all vertices adjacent to this vertex
    for(i=adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
            recursiveDFS(*i, visited);
    }
}

void Graph::DFS(int v)
{
    // Create visited array size of number of indices
    bool *visited = new bool[V];
    
    // Mark all vertices as not visited
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    
    recursiveDFS(v,visited);
}