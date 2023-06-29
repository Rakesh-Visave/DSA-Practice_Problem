// LEETCODE  -- 268. Missing Number
// GEEK-FOR-GEEKS -- missing number


#include<iostream>
#include<vector>
using namespace std;

    int missingNumber(vector<int>& nums) {

        int n = nums.size(); 
        int expectedTotal = (n * (n+1) ) / 2;
        int total = 0;

        for(int i : nums)
        {
            total += i;
        }
        return expectedTotal - total;
        
    }

int main()
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1};

    int missedNumber = missingNumber(nums);

    cout<<"The Missing number in a given Array is: "<<missedNumber;
}