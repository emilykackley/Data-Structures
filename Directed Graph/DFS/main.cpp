#include <iostream>
#include <list>
#include "digraph.h"
using namespace std;

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    
    cout<<"Depth-First Traversal from vertex 2"<<endl;
    g.DFS(0);

    return 0;
}
