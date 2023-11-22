// LEETCODE -- 1424.Diagonal Traverse II


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
     unordered_map<int, vector<int>> mp;
        
        
        for(int row = nums.size()-1; row >= 0; row--) {
            for(int col = 0; col < nums[row].size(); col++) {
                
                mp[row+col].push_back(nums[row][col]);
                
            }
        }
        
        vector<int> result;
        int diagonal = 0;
        
        while(mp.find(diagonal) != mp.end()) {
            
            for(int &num : mp[diagonal]) {
                result.push_back(num);
            }
            diagonal++;
        }
        
        return result;   
    }


int main()
{
    vector<vector<int>> nums = {{1,2,3} , {4,5,6}, {7,8,9}};

    vector<int> ans = findDiagonalOrder(nums);

    cout<<"Element in Diagonal order is: ";
    for(int i : ans)
        cout<<i<<" ";
    
}