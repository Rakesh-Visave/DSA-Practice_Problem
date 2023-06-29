// LEETCODE -- 78. Subsets


#include<vector>
#include<iostream>
using namespace std;

    void solve(vector<vector<int>>& ans, vector<int> output, int index, vector<int> nums)
    {
        if(index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(ans,output,index+1,nums);

        // Include
        int element  = nums[index];
        output.push_back(element);
        solve(ans,output,index+1,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(ans,output,index,nums);
        return ans;
        
    }

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>>ans = subsets(nums);

    for(int i = 0; i<ans.size(); i++)
    {
        cout<<" ,";
           for(int j = 0; j<ans[i].size(); j++)
        {
                cout<<ans[i][j]<<" ";
        }
    }



}