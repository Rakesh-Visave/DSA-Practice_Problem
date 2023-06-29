#include<iostream>
#include<vector>
using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size(); 
        vector<int> ans;

        int total = row * col;
        int count = 0;

        int startingCol = 0;
        int endingCol = col - 1;
        int startingRow = 0;
        int endingRow = row-1;

        while(count < total)
        {
            // for string Row
            for(int i = startingCol; i <= endingCol && count < total; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // for ending column
            for(int i = startingRow; i <= endingRow && count < total; i++ )
            {
                ans.push_back(matrix[i][endingCol]);
                 count++;
            }
            endingCol--;

            // for Ending row 
            for(int i = endingCol; i >= startingCol && count < total; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                 count++;
            }
            endingRow--;

            // staring colums
            for(int i = endingRow; i >= startingRow && count < total; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                 count++;
            }
            startingCol++;    
        }
        return ans;
    }

int main()
{
    vector<vector<int>> matrix = {
                                 {1,2,3},
                                 {4,5,6,},
                                 {7,8,9}};
    
    vector<int> ans = spiralOrder(matrix);
   for(int i :ans)
   {
    cout<<i<<" ";
    }
}