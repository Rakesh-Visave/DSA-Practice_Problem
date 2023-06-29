#include <iostream>
#include <vector>

using namespace std;

    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n ,0);
        for(int i = 0; i < n; i++)
        {
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
        
    }


int main() {

    vector<int> nums = {1,2,1};

    vector<int> result = getConcatenation(nums);

   
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}