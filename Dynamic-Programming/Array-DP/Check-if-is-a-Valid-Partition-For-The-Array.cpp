// LEETCODE -- 2369.Check if There is a Valid Partition For The Array

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

    int n ;
    int dp[1000001];
    bool solve(vector<int> &nums, int i)
    {
        if(i >= n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];

        bool result = false;
        
        // for Rule-1
        if(i+1 < n && nums[i] == nums[i+1])
            result |= solve(nums,i+2);

        // for Rule-2
        if(i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            result |= solve(nums,i+3);

        // for Rule-3
        if( i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            result |= solve(nums,i+3);


        return dp[i] = result;
    }
    bool validPartition(vector<int>& nums) {
         n = nums.size();
         memset(dp,-1, sizeof(dp) );
         return solve(nums,0);
    }


int main()
{
    vector<int> nums = {4,4,4,5,6};
    bool ans = validPartition(nums);

    if(ans)
        cout<<"the array has at least one valid partition";
    else    
        cout<<"The Partition is not possible according to Rule ";
}
