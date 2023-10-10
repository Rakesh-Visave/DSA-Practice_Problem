#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<algorithm>

using namespace std;

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++) {
            
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            
            int in_range  = j - i;
            int out_range = n - in_range;
            
            result = min(result, out_range);
            
        }
        
        return result;
    }

int main()
{
    vector<int> nums = {4,2,5,3};
    int ans = minOperations(nums);

    cout<<"min Operation required to make Array Continuous: "<<ans<<endl;
}
