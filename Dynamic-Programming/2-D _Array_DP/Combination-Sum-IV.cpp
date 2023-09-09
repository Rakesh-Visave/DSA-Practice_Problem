// LEETCODE -- 377.Combination Sum IV

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

    int n;
    int dp[201][1001];
    int solve(int i,vector<int> &nums, int target)
    {
        if(target == 0)
            return 1;

        if(i >= n || target < 0)
            return 0;
        
        if(dp[i][target] != -1 )
            return dp[i][target];
        
        int take_i = solve(0, nums, target - nums[i]);
        int not_take_i = solve(i+1, nums, target);

        return  dp[i][target] = take_i + not_take_i;

    }
    int combinationSum4(vector<int>& nums, int target) {
         n = nums.size();
         memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);   
    }


int main()
{
    vector<int> nums = {1,2,3};
    int target = 4;

    int ans = combinationSum4(nums,target);

    cout<<"the number of possible combinations that add up to target is: "<<ans;
}