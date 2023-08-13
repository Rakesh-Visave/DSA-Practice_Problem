#include<bits/stdc++.h>
using namespace std;

int fibMem(int n, vector<int> &dp)
{
        // Base Case
        if(n ==1 || n==0)
                return n;

        // if solution is calculated and get  the solution from 1-D array and return        
        if(dp[n] != -1)
                return dp[n];
        
        // storing the result of subproblems
        dp[n] = fibMem(n-1,dp) + fibMem(n-2,dp);
        return dp[n];
}

int main()
{
        int n ;
        cin>>n;

        // creat a 1-D array
        vector<int> dp(n+1);
        for(int i = 0; i<=n; i++)
                dp[i] = -1;

        //  fib with Memoization Function
        cout<<fibMem(n,dp)<<endl;
        
        //  fib with Memoization Function
        cout<<fibMem(n,dp)<<endl;
        return 0;
}