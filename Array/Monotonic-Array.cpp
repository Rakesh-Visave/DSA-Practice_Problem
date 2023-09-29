#include<iostream>
#include<vector>
using namespace std;

    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
        bool increasing = false;
        bool decreasing = false;
        
        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) increasing = true;
            
            if(nums[i] > nums[i+1]) decreasing = true;

        }
        
        if(increasing == true && decreasing == true)
                return false;
        
        return true;
    }


int main()
{
    vector<int> nums = {1,2,2,3};

    bool ans = isMonotonic(nums);

    if(ans)
        cout<<"The Array is Monotonic: ";
    else    
        cout<<"Array is not monotonic:";
    
    
}