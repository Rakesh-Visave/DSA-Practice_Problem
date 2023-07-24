#include<iostream>
#include<vector>
using namespace std;

    int recursiveWay(vector<int> &cost ,int n)
    {
        if(n ==0)
            return cost[0];
        if(n == 1)
            return cost[1];
        
        int ans = cost[n] + min(recursiveWay(cost,n-1),recursiveWay(cost,n-2));
        return ans;
    }

    int memoizationWay(vector<int> &cost ,int n,vector<int> &dp)
    {
        if(n ==0)
            return cost[0];
        if(n == 1)
            return cost[1];
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = cost[n] + min(recursiveWay(cost,n-1),recursiveWay(cost,n-2));
        return dp[n];
    }

    int TabulationWay(vector<int> &cost ,int n)
    {
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    
    int optimizeWay(vector<int> &cost ,int n)
    {
        int prev1 = cost[1];
        int prev2 = cost[0];

        for(int i = 2; i<n; i++)
        {
            int curr = cost[i] + min(prev1 ,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // recursive way to find solution  -- but it gives a TLE
        // int n = cost.size();
        // int ans = min(recursiveWay(cost,n-1), recursiveWay(cost,n-2));
        // return ans;

        
        // Recursion + memoization to find the solution
        // int n = cost.size();
        // vector<int> dp(n+1 ,-1);
        // int ans = min(memoizationWay(cost,n-1,dp), memoizationWay(cost,n-2,dp));
        // return ans;


        // Tabulation Method to find the solution
        // int n = cost.size();
        // return TabulationWay(cost,n);

        // optimizeWay-using variable only to find the solution
        int n = cost.size();
        return optimizeWay(cost,n);




    }

int main() {
    vector<int> cost = {10, 15, 20}; 
    int result = minCostClimbingStairs(cost);
    cout << "Minimum cost to climb the stairs: " << result << endl;
    return 0;
}