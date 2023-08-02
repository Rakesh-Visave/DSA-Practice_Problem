    // GEEKFORGEEKS -- Rat in maze problem
#include <bits/stdc++.h>
using namespace std;



    bool isSafe(int x, int y, vector<vector<int>>& visited, int n,vector<vector<int>>& m) 
    { 
        if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        else
            return false;
    }
    void solve(vector<vector<int>>& m, int n, int x, int y, vector<vector<int>>& visited, string path, vector<string>& ans) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down Movement
    int newx = x + 1;
    int newy = y;

    if (isSafe(newx, newy, visited, n, m)) {
        path.push_back('D');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    // Right Movement
    // Right Movement
newx = x;
newy = y + 1;

if (isSafe(newx, newy, visited, n, m)) {
    path.push_back('R');
    solve(m, n, newx, newy, visited, path, ans);
    path.pop_back();
}

// Left Movement
newx = x;
newy = y - 1;

if (isSafe(newx, newy, visited, n, m)) {
    path.push_back('L');
    solve(m, n, newx, newy, visited, path, ans);
    path.pop_back();
}

// Up Movement
newx = x - 1;
newy = y;

if (isSafe(newx, newy, visited, n, m)) {
    path.push_back('U');
    solve(m, n, newx, newy, visited, path, ans);
    path.pop_back();
}


    // Mark current cell as unvisited
    visited[x][y] = 0;
} 
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0)
            return ans;
            
        int scrx = 0;
        int scry = 0;
        
        vector<vector<int>> visited = m;
        
        // Initialize visited matrix as 0
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(m, n, scrx, scry, visited, path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
        
int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1}, 
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
                            
    vector<string>ans = findPath(m,4);
    cout<<"The possible Path of Rat is: "<<endl;
    for(string ch : ans)
    {
        cout<<ch<<" ";
    }
}