#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

    int n;
    bool isValid(vector<int> &nums, int mid , int p)
    {
        int i = 0;
        int countPair = 0;

        while(i < n-1)
        {
            if(nums[i+1] - nums[i] <= mid)
            {
                countPair++;
                i += 2;
            }
            else
                i++;
        }
        return countPair >= p;

    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        n = nums.size();
        int ans = INT_MAX;
        int s = 0;
        int e = nums[n-1] - nums[0];

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(isValid(nums,mid,p))
            {
                ans = mid;
                e =mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }


int main()
{
    vector<int> nums = {10,1,2,7,1,3};
    int p = 2;

    int ans = minimizeMax(nums,p);

    cout<<"inimum maximum difference among all p pairs: "<<ans;
}
