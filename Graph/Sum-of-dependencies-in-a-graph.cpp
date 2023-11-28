// GFG -- Sum of dependencies in a graph



#include <bits/stdc++.h>
using namespace std;


    int sumOfDependencies(vector<int> adj[], int V) {

        int sum = 0;
        for (int i = 0; i < V; ++i) {
            sum += adj[i].size();
        }
        return sum;
    }


int main() {
    
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    // Calculate sum of dependencies
    int dependenciesSum = sumOfDependencies(adj, V);
    cout << "Sum of dependencies in the graph: " << dependenciesSum << endl;

    return 0;
}