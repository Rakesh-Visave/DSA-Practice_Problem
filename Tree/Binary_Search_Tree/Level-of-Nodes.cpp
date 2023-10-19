
#include<bits/stdc++.h>
using namespace std;



	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	     vector<bool> visited(V, false);
        vector<int> level(V, 0);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    level[neighbor] = level[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        if (visited[X])
            return level[X];
        else
            return -1;

	}



int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    int X = 4; // Destination node

    int result = nodeLevel(V, adj, X);

    if (result != -1) {
        cout << "The level of node " << X << " is: " << result << endl;
    } else {
        cout << "Node " << X << " is not reachable." << endl;
    }

    return 0;
}
