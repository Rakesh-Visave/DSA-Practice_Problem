#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
// step-1	Prepare Adj. List
    unordered_map<int, list<int>> adj;
	for(int i =0; i<edges.size(); i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
// step-2 prepare parent array for finding shortest path 
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;

	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	
	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(auto i : adj[front])
		{
			if(!visited[i])
			{
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// step-3 finding path to destination to source by using their parent
    vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode != s)
	{
		currNode = parent[currNode];
		ans.push_back(currNode); 
	}
    // step-4 reverse the path
	reverse(ans.begin(),ans.end());
	return ans;

}


int main() {
    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {2, 4},
        {3, 4}
    };

    int s = 0; // Source node
    int t = 4; // Target node

    // Find the shortest path
    vector<int> path = shortestPath(edges, n, m, s, t);

    // Print the shortest path
    cout << "Shortest Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}
