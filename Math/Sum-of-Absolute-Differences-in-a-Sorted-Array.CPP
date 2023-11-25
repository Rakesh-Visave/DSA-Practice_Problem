// leetcodE -- 1685.Sum of Absolute Differences in a Sorted Array

#include<iostream>
#include<vector>
using namespace std;

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i<n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            int leftSum   = prefixSum[i] - nums[i];
            int rightSum  = prefixSum[n-1] - prefixSum[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
        }
        
        return result;
        
    }


int main()
{
    vector<int> nums = {2,3,5};
    vector<int> ans = getSumAbsoluteDifferences(nums);

    cout<<"Answer is: ";
    for(int i : ans)
        cout<<" "<<i;
}

