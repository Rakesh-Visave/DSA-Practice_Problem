// 239.Sliding Window Maximum

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> deq;

        for(int i = 0; i<n; i++)
        {
            while(!deq.empty() && deq.front() <= i-k)
            {
                deq.pop_front();

            }
            while(!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(i);

            if(i >= k-1)
            {
                result.push_back(nums[deq.front()]);
            }
        } 
        return result;  
    }

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums,k);
    cout<<" the max sliding window is: ";
    for(auto i : ans)
    {
        cout<<" "<<i;
    }
}

