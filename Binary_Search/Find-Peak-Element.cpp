// LEETOCDE -- 162.Find Peak Element

#include<iostream>
#include<vector>
using namespace std;

    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size()-1;
        int highestPeak = 0;
        for(int i = 0; i<n; i++)
        {
            if((i == 0 || nums[i-1] < nums[i] ) && (i == n-1 ||nums[i+1] < nums[i] ))
               highestPeak = i;
        }
        return highestPeak;
    }


int main()
{
    vector<int> nums = {1,2,1,3,5,6,4};

    int index = findPeakElement(nums);
    cout<<"The Peak Element Index is: "<<index;
}
