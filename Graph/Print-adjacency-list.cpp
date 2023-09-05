// GFG -- Print adjacency list


#include <bits/stdc++.h>
using namespace std;


    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
          vector<vector<int>> adjList(V);
        for(auto edge: edges){
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3},{1,2},{3,2}};

    vector<vector<int>> adjList = printGraph(V, edges);

    // Print the adjacency list
    for (int i = 0; i < V; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}