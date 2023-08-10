// LEETCODE -- GFG -- 1143. Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

    int solveRec(string &a, string&b, int i, int j)
    {
        if(i<0 || j< 0)
            return 0;
        
        int ans = 0;
        if(a[i] == b[j])
            ans = 1+ solveRec(a,b, i-1, j-1);
        else
            ans = max(solveRec(a,b,i-1,j), solveRec(a,b,i,j-1));
        
        return ans;
    }

    int solveMem(string &a, string&b, int i, int j,vector<vector<int>> &dp)
    {
        if(i < 0)
            return 0;
        
        if(j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j])
            ans = 1 + solveMem(a,b,i-1,j-1,dp);
        else
            ans = max( solveMem(a,b,i-1,j,dp), solveMem(a,b,i,j-1,dp) );
        
        return dp[i][j] = ans;
        
    }
    
    int solveTab(string &a, string &b,int n , int m)
    {
         
        vector<vector<int>> dp (a.length()+1, vector<int>(b.length()+1,0));
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                int ans = 0;
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
        return dp[n][m];
    }
    
    int solveOptimize(string &a, string &b,int n , int m)
    {
        vector<int> prev(m+1,0), curr(m+1,0);
        
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                int ans = 0;
                if(a[i-1] == b[j-1])
                    curr[j] = 1+ prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
            
        }
        return prev[m];
    }

    int lcs(int n, int m, string s1, string s2)
    {
        // return solveRec(s1,s2,n-1,m-1);
        
        // vector<vector<int>> dp (s1.length(), vector<int>(s2.length(),-1));
        // return solveMem(s1,s2,n-1,m-1,dp);  
        
        // return solveTab(s1,s2,n,m);
        
        return solveOptimize(s1,s2,n,m);
    }

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int n = 6;
    int m =6;

    int ans = lcs(n,m,s1,s2);
    cout<<"length of longest subsequence present in both of them is: "<<ans;
}