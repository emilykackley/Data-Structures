#include <iostream>
#include <list>
using namespace std;

#ifndef DIGRAPH_H
#define DIGRAPH_H

class Graph
{
    // Number of vertices
    int V;
    // Pointer to an array for adjacency lists
    list<int> *adj;
    
    public:
        // Constructor
        Graph(int V); 
        
        // Add an edge to the graph 
        void addEdge(int v, int w);
        
        // Recursive function for DFS
        void recursiveDFS(int v, bool visited[]);
        
        // Depth-first traversal of all vertices starting
        //   from v 
        void DFS(int v);
};

#include "digraph.hpp"
#endif //DIGRAPH_H