// GFG -- string-permutation


#include<bits/stdc++.h>
using namespace std;


   void helper(int i,vector<string>&ans,string s){
        if(i==0){
            ans.push_back(s);
        }
        for(int ind=i;ind>=0;ind--){
            swap(s[i],s[ind]);
            helper(i-1,ans,s);
            swap(s[i],s[ind]);
        }
    }
    vector<string> permutation(string S)
    {
         vector<string> ans;
        helper(S.size()-1,ans,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
