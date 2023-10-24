
#include <bits/stdc++.h>
using namespace std;

        bool isPalin(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    int check(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(isPalin(i,j,s)) return dp[i][j] = 0;

        int out = INT_MAX;
        for(int k = i;k<j;++k){
            if(isPalin(i,k,s)){
                out = min(out,1 + check(k+1,j,s,dp));
            }
        }
        return dp[i][j] = out;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        check(0,n-1,str,dp);
        return check(0,n-1,str,dp);
    }

int main() {
    string input = "nitin"; // Change this to test different inputs
    int result = palindromicPartition(input);
    cout << "Minimum cuts needed: " << result << endl;
    return 0;
}