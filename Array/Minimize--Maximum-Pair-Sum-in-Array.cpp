// LEETCODe -- 1877.Minimize Maximum Pair Sum in Array

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    int minPairSum(vector<int>& nums) {
         sort(begin(nums), end(nums));

        int maxResult = 0;
        
        int i = 0, j = nums.size()-1;
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            
            maxResult = max(maxResult, sum);
            i++;
            j--;
        }
        
        return maxResult;
  
    }


int main()
{
    vector<int> nums = {3,5,2,3};
    int ans = minPairSum(nums);

    cout<<"The minimized maximum pair sum after optimally pairing up the elements: "<<ans; 
}