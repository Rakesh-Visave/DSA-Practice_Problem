#include<iostream>
#include<vector>
using namespace std;

    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftsum(n,0);
        for(int i = 1; i < n; i++)
        {
            leftsum[i] = leftsum[i-1] + nums[i-1];
        }

        vector<int> rightsum(n,0);
        for(int i = n-2; i >= 0; i--)
        {
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }

        vector<int> ans(n,0);
        for(int i = 0; i < n; i++)
        {
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;
        
    }


int main()
{
    vector<int> nums = {10,4,8,3};

    vector<int> ans = leftRightDifference(nums);
    cout<<"the left and right sum diffrence is:";
    for(int i : ans)
    {
        cout<<" "<<i;
    }
}