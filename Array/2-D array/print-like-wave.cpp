// CODESTUDIO -- print like wave

#include <bits/stdc++.h> 
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int>ans;
    for(int i = 0; i < mCols; i++)
    {
        if(i&1)
        {
            for(int j = nRows - 1; j>=0; j--)
            {
              ans.push_back(arr[j][i]);  
            }
        }
        else
        {
            for(int j = 0; j < nRows; j++)
            {
                ans.push_back(arr[j][i]);  
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {
                                 {1,2,3,4},
                                 {5,6,7,8},
                                 {9,10,11,12}};
    
    vector<int> ans = wavePrint(arr,3,4);
   for(int i :ans)
   {
    cout<<i<<" ";
   }
}