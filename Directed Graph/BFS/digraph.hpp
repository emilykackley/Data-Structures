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

void Graph::BFS(int s)
{
    // Mark all vertices as not visited
    bool *visited = new bool[V];
    for(int i=0; i <V; i++)
    {
        visited[i] = false;
    }
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark current node as visited and enqueue
    visited[s] = true;
    queue.push_back(s);
    
    // Use i to get all adjacent vertices of vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue vertex from queue and print
        s = queue.front();
        cout<< s << " ";
        queue.pop_front();
        
        // Gets all adjacent vertices of the dequeued
        //   vertex s.
        // If an adjacent vertex has not been visited
        //   mark it visited and enqueue the vertex 
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    };
}