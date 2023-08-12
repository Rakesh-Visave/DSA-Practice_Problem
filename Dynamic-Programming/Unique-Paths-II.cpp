#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

    int m,n;
    int dp[101][101];
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if(i >= m || j >= n || grid[i][j] == 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m-1 && j == n-1)
            return 1;
        
        
        int right = solve(grid, i, j+1);
        int down = solve(grid, i+1, j);

        return dp[i][j] = down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(dp, -1 ,sizeof(dp));

        return solve(obstacleGrid,0,0);
        
    }

int main()
{
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};

    int ans = uniquePathsWithObstacles(grid);

    cout<<"The number of possible unique paths that the robot can take to reach the bottom-right corner: "<<ans;
    
}