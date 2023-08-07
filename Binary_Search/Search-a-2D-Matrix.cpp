// LEETCODE -- 74. Search a 2D Matrix

#include<vector>
#include<iostream>
using namespace std;

//Approach-1 O(m*n)
class Solution {
public:
    bool searchMatrixbetter(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0, j = n-1;
        
        while(i < m && j >= 0) {
            if(matrix[i][j] > target) {
                j--;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        
        return false;
    }
};


//Approach-2 (Using Binary Search) O(log(m*n))

    bool searchMatrixOptimzed(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end   = m*n-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            int row = mid/n;
            int col = mid%n;
            
            if(matrix[row][col] > target) {
                end = mid-1;
            } else if(matrix[row][col] < target) {
                start = mid+1;
            } else {
                return true;
            }
        }
        
        return false;
        
    }


int main()
{
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    int target = 3;

    bool ans = searchMatrixOptimzed(matrix,target);

    if(ans)
        cout<<"The target is present";
    else    
        cout<<"The Target is not present";
}