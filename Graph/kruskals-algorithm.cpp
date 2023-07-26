#include<algorithm>	
#include<vector>
#include<iostream>
using namespace std;

  bool cmp(vector<int> &a , vector<int> &b)
	{
	    return a[2] < b[2];
	}   
	void makeSet(vector<int> &parent , vector<int> &rank, int n)
	{
	    for(int i = 0; i < n; i++)
	    {
	        parent[i] = i;
	        rank[i] = 0;
	    }
	}
	
	int findParent(vector<int> &parent, int node)
	{
	    if(parent[node] == node)
	        return node;
	       
	   return parent[node] = findParent(parent,parent[node]);
	}
	void unionSet(int u, int v, vector<int> &parent ,vector<int> &rank)
	{
	    u = findParent(parent,u);
	    v = findParent(parent,v);
	    
	    if(rank[u] < rank[v])
	        parent[u] = v;
	       
	   else if(rank[v] < rank[u])
	        parent[v] = u;
	       
	   else
     {
	    parent[v] = u;
	    rank[u]++;
     }
	}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // step 1 - Sort edges according to weights
    sort(edges.begin(),edges.end(),cmp);
            
            vector<int> parent(n);
            vector<int> rank(n);
            makeSet(parent,rank,n);
            
            int minWeight = 0;
            for(int i = 0; i<edges.size(); i++)
            {
                // step 2 - find parent of both node
                int u = findParent(parent,edges[i][0]);
                int v = findParent(parent,edges[i][1]);
                int wt = edges[i][2];
                
                // step 3 -if thier parent is not same then union that node
                if(u != v)
                {
                    minWeight +=wt;
                    unionSet(u,v,parent,rank);
                }
            }
        return minWeight;
}

int main()
{
    int n = 4; // Number of nodes in the graph
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    
    int minWeight = minimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree Weight: " << minWeight << endl;

    return 0;
}