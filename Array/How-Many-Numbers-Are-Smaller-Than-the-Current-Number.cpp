#include<iostream>
#include<vector>
using namespace std;


    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    count++;
                }
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }

int main()
{
    vector<int> nums = {8,1,2,2,3};

    vector<int> ans = smallerNumbersThanCurrent(nums);

    cout<<"this Numbers Are Smaller Than the Current Number ";
    for(int i : ans)
    {
        cout<<" "<<i;
    }
}


