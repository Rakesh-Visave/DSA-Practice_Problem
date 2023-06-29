// LEETCODE -- 283. Move Zeroes


#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums);

    void moveZeroes(vector<int>& nums) {

        int nonZero = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[nonZero]);
                nonZero++;
            }
        }
        
    }

int main()
{
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    cout<<"After Moving Zeros the Array is: ";
    for(int i : nums)
    {
        cout<<i <<" ";
    }
}