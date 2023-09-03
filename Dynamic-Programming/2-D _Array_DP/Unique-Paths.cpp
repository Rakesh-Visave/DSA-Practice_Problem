// LEETCODE -- 62.Unique Paths
#include<iostream>
#include<cstring>
using namespace std;

    int dp[101][101];
    int solve(int i , int j, int m, int n)
    {
        if(i >= m || j >= n)
            return 0;
        if(i == m-1 || j == n-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        

        
        int right = solve(i,j+1,m,n);
        int down = solve(i+1,j,m,n);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
       memset(dp,-1 ,sizeof(dp));
       return solve(0,0,m,n);

    }


int main()
{
    int m = 3 , n = 7;
    int ans = uniquePaths(m,n);
    cout<<"number of possible unique paths that the robot can take to reach the bottom-right corner: "<<ans;
}