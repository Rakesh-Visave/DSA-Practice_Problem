#include<iostream>
#include<vector>
using namespace std;

int catalan(int n,vector<int> &dp)
{
    if(n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];
    
    int res = 0;
    for(int i =0; i<=n-1; i++)
    {
        res += catalan(i,dp) * catalan(n-i-1,dp);
    }
    return dp[n] = res;
}
int main()
{
    int n = 10;
    vector<int>dp(n+1,-1);
    for(int i = 0; i<n; i++)
    {
        cout<<catalan(i,dp)<<" ";
    }
}