// LEETCODE -- 74. Search a 2D Matrix

#include<iostream>
#include<vector>
using namespace std;


    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int s = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        int e = row*col -1;
        int mid = s + (e-s) / 2;

        while(s <= e)
        {
            int element = matrix[mid / col][mid % col];
            if(element == target)
                return 1;

            if(target > element)
                s = mid+1;
            else
                e= mid-1;
            
            mid = s+(e-s)/2;
        }
        return 0;
        
    }

int main()
{
    vector<vector<int>> matrix  = {{1,2,3},{4,5,6},{7,8,9}};

    int target = 30;

    bool ans = searchMatrix(matrix, target);

    if(ans)
    {
        cout<<"Found ";
    }
    else
    {
        cout<<"Not Found";
    }
}