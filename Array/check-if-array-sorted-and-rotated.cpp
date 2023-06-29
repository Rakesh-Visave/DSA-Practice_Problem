#include<iostream>
#include<vector>
using namespace std;


    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                count++;
            
            }
        }
            if(nums[n-1] > nums[0])
            {
                count++;
                
            }
        
        return count <= 1;
        
    }


int main()
{
    vector<int> nums = {1,2,3};

    bool value = check(nums);
    
     if(value)
     {
        cout<<"Given Array is Sorted and rotated";
     }
     else
     {
        cout<<"Given Arrya is not a Sorted And Rotated";
     }
}