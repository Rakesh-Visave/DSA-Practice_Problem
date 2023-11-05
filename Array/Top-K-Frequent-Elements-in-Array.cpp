//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


    vector<int> topK(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
        for (auto i : nums)
            ++mp[i];
        
        priority_queue<pair<int, int>> pq;
        
        for (auto itr : mp) {
            pq.push({itr.second, itr.first});
        }
        
        vector<int> out;
        while (!pq.empty() && k--) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        
        return out;

    }

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    
    vector<int> ans = topK(nums,k);

    cout<<"Top k frequent element in the array is: ";
    for(int i : ans)
        cout<<" "<<i;

}