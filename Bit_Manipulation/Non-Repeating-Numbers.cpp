// GFG -- Non Repeating Numbers


#include<bits/stdc++.h>
using namespace std;

    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            ans ^=nums[i];
        }
        
        // we need to find right most element formula is x & ~(x-1)
        ans = ans & ~(ans-1);
        
        // separate the number in int set1 and set2
        int set1 = 0;
        int set2 = 0;
        for(int i = 0; i<n; i++)
        {
            if(ans & nums[i])
                set1 ^= nums[i];
            else
                set2 ^= nums[i];
        }
        vector<int> result;
        result.push_back(set1);
        result.push_back(set2);
        
        sort(result.begin(),result.end());
        
        return result;
    }

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNumber(nums);

    cout<<"Non-Reapting Number are: ";
    for(auto i: ans)
    {
        cout<<i<<" ";
    }


}