#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;


bool checkCycle(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node])
    {
      if(!visited[neighbour])
      {
        bool cycleDetected = checkCycle(neighbour,visited,dfsVisited,adj);
        if(cycleDetected)
          return true;
      }
      else if(dfsVisited[neighbour])
        return true;
    }
    dfsVisited[node] = false;
    return false;
}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adj;
  for(int i = 0; i<edges.size();i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;

  for(int i = 0; i<n; i++)
  {
    if(!visited[i])
    {
      bool cycleFound = checkCycle(i,visited,dfsVisited,adj);
      if(cycleFound)
        return true;
    }

  }
  return false;
}

int main() {
    int n = 6; // Number of vertices
    vector<pair<int, int>> edges = {{1, 0}, {0, 2}, {3, 1}, {2, 3}, {2, 4}, {3, 5}}; // Edges in the graph

    bool cycleExists = detectCycleInDirectedGraph(n, edges);

    if (cycleExists) {
        cout << "Cycle exists in the directed graph." << endl;
    } else {
        cout << "No cycle exists in the directed graph." << endl;
    }

    return 0;
}
