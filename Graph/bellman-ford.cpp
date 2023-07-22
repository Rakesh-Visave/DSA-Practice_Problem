#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u]+wt;
            }
        }
    } 
    // checking negetive cycle
    bool flag = 0;
    for(int j = 0; j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                flag = 1;
            }
        }
    if(flag == 0)
        return dist[dest];
    return -1;
}

int main() {
    int n = 5;
    int m = 7;

    vector<vector<int>> edges = {
        {1, 2, 6},
        {1, 3, 3},
        {2, 3, 2},
        {2, 4, 5},
        {3, 4, 3},
        {4, 2, 1},
        {4, 5, 2}
    };

    int src = 1;
    int dest = 5;

    int shortestDistance = bellmonFord(n, m, src, dest, edges);
    if (shortestDistance == -1) {
        cout << "Negative cycle detected. No shortest path exists." << endl;
    } else {
        cout << "Shortest distance from node " << src << " to node " << dest << " is: " << shortestDistance << endl;
    }

    return 0;
}
