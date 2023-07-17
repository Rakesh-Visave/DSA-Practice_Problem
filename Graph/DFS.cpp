#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
void dfs(int node,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adjList,vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i:adjList[node])
    {
        if(!visited[i])
            dfs(i,visited,adjList,component);
    }
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int> > adjList;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);    
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i = 0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }

    }
    return ans;

}

int main() {
    int V = 6; // Number of vertices
    int E = 6; // Number of edges

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}}; // Edges in the graph

    vector<vector<int>> dfsResult = depthFirstSearch(V, E, edges);

    cout << "Connected components:\n";
    for (int i = 0; i < dfsResult.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < dfsResult[i].size(); j++) {
            cout << dfsResult[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
