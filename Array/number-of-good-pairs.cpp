#include<iostream>
#include<vector>

using namespace std;

    int numIdenticalPairs(vector<int>& nums) {
        vector<int> temp(101);
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            result += temp[nums[i]];
            temp[nums[i]]++;
        }
        return result;
    }

 
 int main()
 {
    vector<int> nums = {1,2,3,1,1,3};

    int result = numIdenticalPairs(nums);

    cout<<"The Number of Good Pairs is :"<<result;
 }