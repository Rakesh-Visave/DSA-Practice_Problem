// LEETCODE -- 46. Permutations

#include<iostream>
#include<vector>
using namespace std;

    void solve(vector<int> nums, vector<vector<int>>& ans, int index)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j = index; j<nums.size(); j++)
        {
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            // backtracking
            swap(nums[index],nums[j]);

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int index = 0;
        solve(nums,ans,index);
        return ans;
        
    }

int main()
{
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permute(nums);
    cout<<"The All permutation of given Array Vector are :"<<endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<",";
        for(int j = 0; j < ans[0].size(); j++)
        {
            cout<<ans[i][j];
        }
    }
}