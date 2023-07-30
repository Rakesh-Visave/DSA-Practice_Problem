#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

int solveRec(vector<int> nums, int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    int incl = solveRec(nums , n-2) + nums[n];
    int excl = solveRec(nums , n-1) + 0;

    return max(incl,excl);
}

int solveMem(vector<int> nums, int n,vector<int> &dp)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    if(dp[n] != -1)
        return dp[n];
    
    int incl = solveRec(nums , n-2) + nums[n];
    int excl = solveRec(nums , n-1) + 0;

    return dp[n] = max(incl,excl);
}

int solveTab(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp (n,0);

    dp[0] = nums[0];

    for(int i = 1; i<n; i++)
    {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl,excl);
    }
    return dp[n-1];
}

int solveOpt(vector<int> nums)
{
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;

    for(int i = 1; i<n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans  = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // return solveRec(nums,n-1);

    // vector<int>dp(n ,-1);
    // return solveMem(nums,n-1,dp);

    // return solveTab(nums);

    return solveOpt(nums);

}


int main()
{
    vector<int> nums = {2, 1, 4, 9};
    int ans = maximumNonAdjacentSum(nums);
    cout<<"Maximum Sum of Non Adjacent element is: "<<ans;
    
}