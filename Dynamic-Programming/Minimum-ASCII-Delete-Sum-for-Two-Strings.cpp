// LEETCODE -- 712. Minimum ASCII Delete Sum for Two Strings
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;


    int n,m;
    int t[1001][1001];
    int solve(int i, int j, string &s1, string &s2)
    {
        if(i >= m && j >= n)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        


        if(i >= m)
            return t[i][j] =  s2[j] + solve(i,j+1,s1,s2);
        else if( j >= n)
           return  t[i][j] = s1[i] + solve(i+1, j,s1,s2);
        
        if(s1[i] == s2[j])
           return  t[i][j] = solve(i+1,j+1,s1,s2);
        
        int delete_i = s1[i] + solve(i+1,j,s1,s2);
        int delete_j = s2[j] + solve(i, j+1,s1,s2);

        return t[i][j] = min(delete_i , delete_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();

        return solve(0,0,s1,s2);

    }

int main()
{
    string s1 = "delete";
    string s2 = "leet";

    int ans = minimumDeleteSum(s1,s2);

    cout<<"the lowest ASCII sum of deleted characters to make two strings equal is: "<<ans;

}
