//
// Created by Muhmd on 10/8/2020.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


class Graph
{

private:

    int v;
    list<int> *adj;

public:

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s)
    {
        queue<int> q;
        bool visited[v];
        for (int i = 0; i < v; i++)
            visited[i] = false;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            for (auto it : adj[q.front()])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
            cout << q.front() << " ";
            q.pop();
        }
    }

    void DFSRec(int s, bool visited[])
    {
        cout << s << " ";
        visited[s] = true;
        for (auto it : adj[s])
        {
            if (!visited[it])
                DFSRec(it, visited);
        }
    }

    void DFS(int s)
    {
        bool visited[v];
        for (int i = 0; i < v; i++)
            visited[i] = false;
        DFSRec(s, visited);
    }

    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }
};


#endif //GRAPH_GRAPH_H
