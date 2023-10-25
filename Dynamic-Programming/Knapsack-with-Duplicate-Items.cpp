// GFG -- Knapsack with Duplicate Items

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int w = wt[i]; w <= W; w++) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }


int main()
{
    int n = 2;
    int w = 3;

    int val[2] = {1,1};
    int wt[2] = {2,1};

    int ans = knapSack(n,w,val,wt);

    cout<<"The Maximum profit is:" <<ans;
}