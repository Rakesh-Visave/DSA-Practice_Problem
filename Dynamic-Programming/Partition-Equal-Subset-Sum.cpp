
#include <bits/stdc++.h>
using namespace std;


bool canPart(int& N, int i, int arr[], int target, vector<vector<int>>& dp){
    if(target == 0)
            return true;
        
        if(i >= N)
            return false;
           
        if(target >= arr[i]){
            bool take = canPart(N,i+1,arr,target - arr[i], dp);
            if(take)
                return dp[i][target] = true;
        }
        
        bool notTake = canPart(N,i+1,arr,target, dp);
        return dp[i][target] = notTake;
    }
    
   
    int equalPartition(int N, int arr[])
    {
      int sum = 0;
        for(int i = 0; i<N;++i){
            sum += arr[i];
        }
        if(sum&1)
            return false;
            
        int target = sum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return canPart(N,0,arr,target, dp);
    }

int main()
{
    int N = 4; 
    int arr[N] = {1,5,11,5};

    int ans = equalPartition(N,arr);
    if(ans)
        cout<<"Equal Partition is applicable";
    else    
        cout<<"Equal partition is not applicable";
}