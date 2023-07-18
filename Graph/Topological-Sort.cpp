#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<list>
#include<iostream>
using namespace std;


void topoSort(int node, vector<bool> &visited, unordered_map<int ,list<int>> &adj,stack<int> &s)
{
    visited[node] = 1;
    for(auto neighbour :adj[node])
    {
        if(!visited[neighbour])
            topoSort(neighbour,visited,adj,s);

    }
    s.push(node);     
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int> > adj;
    for(int i = 0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;

    for(int i = 0; i<v; i++)
    {
        if(!visited[i])
            topoSort(i,visited,adj,s);
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}

int main()
{
    int v = 6;  // Number of vertices
    int e = 6;  // Number of edges

    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> sortedOrder = topologicalSort(edges, v, e);

    cout << "Topological Sort: ";
    for (int node : sortedOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
