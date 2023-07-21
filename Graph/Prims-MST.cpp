#include<unordered_map>
#include<list>
#include<limits.h>
#include <bits/stdc++.h> 
#include<vector>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i = 0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i = 0; i<=n;i++)
    {
        key[i]= INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i= 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // finding min value node
        for(int v =1; v<=n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adj nodes
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w< key[v])
            {
                  parent[v] = u;  
                  key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i<=n; i++)
    {
        ans.push_back({{parent[i],i} ,key[i]});
    }
    return ans;

}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // Number of nodes
    int m = 15; // Number of edges

    // Hardcoded input in the form of vector of edges (pairs) and their weights
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 21},
        {{2, 1}, 16},
        {{2, 1}, 12},
        {{2, 3}, 13},
        {{2, 4}, 18},
        {{2, 5}, 15},
        {{3, 2}, 13},
        {{3, 5}, 17},
        {{4, 1}, 16},
        {{4, 5}, 19},
        {{5, 1}, 18},
        {{5, 2}, 15},
        {{5, 3}, 17},
        {{5, 4}, 19}

  };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    // Outputting the Minimum Spanning Tree
    cout << "Minimum Spanning Tree:" << endl;
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
