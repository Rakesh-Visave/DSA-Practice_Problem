#include<vector>
#include<iostream>
using namespace std;

    int findDuplicate(vector<int>& nums) {
        // Simmilar as detect starting point of cycle in LinkedList
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];   
        }
        return slow;

    }

int main()
{
    vector<int> nums ={1,3,4,2,2};
    int ans = findDuplicate(nums);
    cout<<"The Duplicate number in given Array is: "<<ans;
}