#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

    int t[23][23];
    int solve(vector<int> &nums ,int i, int j)
    {
        if(i > j)
            return 0;
        if(i == j)
            return nums[i];
        if(t[i][j] != -1)
            return t[i][j];
        
        int take_i = nums[i] - solve(nums, i+1, j);
        int take_j = nums[j] - solve(nums,i,j-1);

        return t[i][j] =  max(take_i, take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {    
     int n = nums.size();
     memset(t, -1,sizeof(t));

     return solve(nums,0,n-1) >= 0;   
    }

int main()
{
    vector<int> nums = {1,5,233,7};

    bool ans = PredictTheWinner(nums);
     if(ans)
        cout<<"Player 1 can win the game";
    else    
        cout<<"Player 2 can win the game";
}