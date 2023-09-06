
#include<bits/stdc++.h>
using namespace std;

    void dfs(int i, vector<int>adj[], vector<int>& vis, vector<int>& topo){
        vis[i] = 1;
        for(auto edge: adj[i]){
            if(!vis[edge]){
                dfs(edge, adj,vis,topo);
            }
        }
        topo.push_back(i);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int cnt = 0;
	    vector<int> vis(V,0), topo;
	    for (int i = 0; i < V; ++i) {
            if (!vis[i])
                dfs(i,adj,vis,topo);
        }
	    
	    if(topo.size() == V){
            int motherVer = topo.back();
	        vis.assign(V, 0);
            topo.clear();
	        dfs(motherVer, adj, vis, topo);
	        // for(auto i: topo)
	        //     cout<<i<<" ";
	        if(topo.size() == V)
	            return motherVer;
	    }
	    
	    return -1;
	}

int main() {
    int V = 7; // Number of vertices
    vector<int> adj[V];

    // Hardcoded edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[4].push_back(6);
    
    int motherVertex = findMotherVertex(V, adj);

    if (motherVertex != -1)
        cout << "The mother vertex is: " << motherVertex << endl;
    else
        cout << "There is no mother vertex in the graph." << endl;

    return 0;
}
