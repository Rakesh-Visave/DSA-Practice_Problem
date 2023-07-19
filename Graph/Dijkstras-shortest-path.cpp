#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    
    // step-1 prepare Adj. list with weight
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // used dist vector to store shortest distance
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;

    // initialize source node with 0 distance and insert into set
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty()) {

        // find top of set
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        
        // pop the top
        st.erase(st.begin());

        
        for (auto neighbour : adj[topNode]) {
            if (nodeDistance + neighbour.second < dist[neighbour.first]) {
                // find node is already present in set 
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if finds delete that record
                if (record != st.end()) {
                    st.erase(record);
                }
                // if not find update distance and insert into the set
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main() {
    int vertices = 4; // Number of vertices in the graph
    int edges = 5;    // Number of edges in the graph
    int source = 0;   // Source node for Dijkstra's algorithm

    // Each element in vec represents an edge: [u, v, w], where u and v are nodes and w is the edge weight.
    vector<vector<int>> vec = {
        {0, 1, 5}, // Edge from node 0 to node 1 with weight 5
        {0, 1, 5}, // Edge from node 0 to node 1 with weight 5
        {0, 2, 8}, // Edge from node 0 to node 2 with weight 8
        {1, 2, 9},// Edge from node 1 to node 3 with weight 9
        {1, 3, 2}, // Edge from node 1 to node 3 with weight 2
        {2, 3, 6}, // Edge from node 2 to node 3 with weight 6
      
    };

    vector<int> shortestDistances = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from node " << source << " to all other nodes:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
