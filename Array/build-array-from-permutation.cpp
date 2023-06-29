#include <iostream>
#include <vector>

using namespace std;


vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0 ;i < n; i++)
        {
          ans[i] = nums[nums[i]];  
        }
        return ans;
        
    }


int main() {

    vector<int> nums = {0,2,1,5,3,4};

    vector<int> result = buildArray(nums);

   
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
