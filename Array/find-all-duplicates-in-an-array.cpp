
#include<iostream>
#include<vector>
using namespace std;

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return ans;
        
    }

int main()
{
    vector<int> nums = {10,2,5,10,9,1,1,4,3,7};

    vector<int> ans = findDuplicates(nums);

    cout<<"Duplicate Elements are: "<<endl;
    for(int i : ans)
    {
        cout<<i <<" "<<endl;
    }
}