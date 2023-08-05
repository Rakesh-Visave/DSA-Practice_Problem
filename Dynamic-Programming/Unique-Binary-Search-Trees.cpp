#include<vector>
#include<iostream>
using namespace std;

    int solve(int n , vector<int> &dp)
    {
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        for(int i = 1; i<=n; i++)
        {
            ans += solve(i-1,dp) * solve(n-i,dp);

        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
int main()
{
    int n = 3;
    cout<<"the number of structurally unique BST's are:  "<<numTrees(n);
}