// LEETCODE -- 815.Bus Routes


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
     if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;
        
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        
        for (auto route : adj[source]){
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();

            while(size--) {
                int route = que.front();
                que.pop();

                
                for (auto &stop: routes[route]) {
                    
                    if (stop == target) {
                        return busCount;
                    }

                    
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;   
    }


int main()
{
    vector<vector<int>> routes = {{1,2,7}, {3,6,7}};
    int source = 1;
    int target = 6;

    int ans = numBusesToDestination(routes,source,target);
    cout<<" the least number of buses you must take to travel from source to target:"<<ans;

}