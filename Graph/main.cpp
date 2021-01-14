#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 6);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(6, 1);
    g.addEdge(6, 4);
    g.DFS(0);
    return 0;
}
