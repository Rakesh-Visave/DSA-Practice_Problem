#include<iostream>
#include<vector>

using namespace std;

    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);

        int j = 0;
        for(int i = 0;i < 2*n; i = i+2)
        {
            ans[i]=nums[j];
            ans[i+1] = nums[j+n];
            j++;
        }
        return ans;
        
    }
int main()
{
        vector<int> nums =  {2,5,1,3,4,7};
        vector<int> ans =  shuffle(nums,3);
        cout << "Result: ";
        for (int num : ans) {
        cout << num << " ";
        }
        
        
        return 0;
} 