#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<set>
#include<vector>
using namespace std;

void prepareAdjList(unordered_map<int, set<int> > &adjList, vector<pair<int, int>> &edges)
{
    for(int i =0; i<edges.size(); i++)
    {
        int v = edges[i].first;
        int u = edges[i].second;

        adjList[v].insert(u);
        adjList[u].insert(v);
    }
}
void bfsTraversal(unordered_map<int,set<int> > &adjList, unordered_map<int, bool> &visited,vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        for(auto i:adjList[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] =1;

            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList,edges);

    for(int i = 0; i<vertex; i++)
    {
        if(!visited[i])
            bfsTraversal(adjList,visited,ans,i);
    }
    return ans; 

}

int main() {
    int vertex = 6; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}}; // Edges in the graph

    vector<int> bfsResult = BFS(vertex, edges);

    cout << "BFS traversal: ";
    for (int i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i] << " ";
    }
    cout << endl;

    return 0;
}
