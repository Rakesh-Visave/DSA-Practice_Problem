// GFG -- Winner of an election

//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


    vector<string> winner(string arr[],int n)
    {
         unordered_map<string,int> mp;
        for(int i = 0; i < n ; ++i)
            ++mp[arr[i]];
        
        string out;
        int cnt = 0;
        for(auto i: mp){
            if(cnt < i.second){
                cnt = i.second;
                out = i.first;
            } else if(cnt == i.second){
                if(out > i.first)
                    out = i.first;
            }
        }
        return {out, to_string(cnt)};
    }

int main()
{
    int n = 13;
    string arr [n] = {"john" ,"johnny","jackie","johnny","john" 
"jackie","jamie","jamie","john","johnny","jamie",
"johnny","john"};

vector<string> ans = winner(arr,n);

    for(string str : ans)
    {
        cout<<" "<<str;
    }
}

