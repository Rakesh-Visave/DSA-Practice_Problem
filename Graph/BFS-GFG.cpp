
#include <bits/stdc++.h>
using namespace std;
 
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<int> vis(V,0);
        vis[0] = 1;
        
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto x :adj[frontNode])
            {
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans;
    }

    int main() {
    int V = 5; // Number of vertices
    int E = 6; // Number of edges

    vector<int> adj[V];
    int edges[][2] = { {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 5}, {4, 5} };

    // Adding edges to the adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u - 1].push_back(v - 1);
        // Uncomment the line below if the graph is undirected
        // adj[v - 1].push_back(u - 1);
    }

    vector<int> ans =bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}





