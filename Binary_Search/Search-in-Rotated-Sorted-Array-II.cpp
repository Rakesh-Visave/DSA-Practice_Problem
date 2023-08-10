// LEETCODE -- 81. Search in Rotated Sorted Array II

#include<iostream>
#include<vector>
using namespace std;

    int findPivot(vector<int> &nums , int s, int e)
    {
        while(s < e)
        {
            while(s < e && nums[s] == nums[s+1])
                s++;
            
            while(e >= s && nums[e] == nums[e-1])
                e--;
    
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e])
                s = mid+1;
            else
                e = mid;
        }
        return e;
    }

    bool binarySearch(vector<int> &nums,int s, int e,int target)
    {
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] < target)
                s = mid+1;
            else
                e = mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {

        int n = nums.size();
        int pivot = findPivot(nums,0,n-1);

        if(binarySearch(nums,0,pivot-1,target))
            return true;
        return binarySearch(nums,pivot,n-1,target);
    }
int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 6;

    bool ans = search(nums,target);
    if(ans) 
        cout<<"The Target is present";
    else
        cout<<"The Target  is not present";
        
}
