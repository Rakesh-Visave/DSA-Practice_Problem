// LEETCODE -- 1464.Maximum Product of Two Elements in an Array

#include<iostream>
#include<vector>
using namespace std;

    int maxProduct(vector<int>& nums) {
          int n = nums.size();
        
        int maxNum = nums[0];
        int result = 0;
        
        for(int i = 1; i<n; i++) {
            result = max(result, (maxNum-1)*(nums[i]-1));
            maxNum = max(maxNum, nums[i]);
        }
        
        return result;
    }


int main()
{
    vector<int> nums = {3,4,5,2};

    int ans = maxProduct(nums);

    cout<<"the maximum value of (nums[i]-1)*(nums[j]-1): "<<ans;
}