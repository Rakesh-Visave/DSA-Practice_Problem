// LEETCODE - 1480. Running Sum of 1d Array


#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {

    int sum = 0;
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++)
    {
        sum += nums[i];
        ans.push_back(sum);
    }
    return ans;
        
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> ans = runningSum(nums);

    cout<<"The Running sum of the given vector Array is: ";
    for(int i :ans)
    {
        cout<<" "<<i;
    }    
}
