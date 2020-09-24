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
        
        // Print BFS traversal from source s 
        void BFS(int s);
};

#include "digraph.hpp"
#endif //DIGRAPH_H