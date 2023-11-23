// LEETCODE -- 1630.Arithmetic Subarrays


#include<iostream>
#include<unordered_set>
#include<vector>
#include<climits>

using namespace std;

        bool check(vector<int> &arr) {
        int n = arr.size();
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> st;
        
        for (int &num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            st.insert(num);
        }
        
        if((maxElement-minElement) % (n-1) != 0)
            return false;
        
        int diff = (maxElement-minElement)/(n-1);
        int curr = minElement + diff;
        
        
        
        while(curr < maxElement) {
            if(st.find(curr) == st.end()) {
                return false;
            }
            curr += diff;
        }
        
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
         int m = l.size();
        
        vector<bool> result;
        
        for(int i = 0; i<m; i++) {
            
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            
            result.push_back(check(arr));
            
        }
        
        return result;
    }


int main()
{
    vector<int> nums = {4,6,5,9,3,7};
    vector<int> l = {0,0,2};
    vector<int> r = {2,3,5};

    vector<bool> ans = checkArithmeticSubarrays(nums,l,r);

    cout<<"Answer is: ";
    for(bool i : ans)
        cout<<" "<<i;
    
}