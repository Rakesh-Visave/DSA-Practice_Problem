// 1727.Largest Submatrix With Rearrangements


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    int largestSubmatrix(vector<vector<int>>& matrix) {
          int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        for(int row = 0; row < m; row++) {
            
            for(int col = 0; col < n; col++) {
                
                if(matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
                
            }
            
            
            vector<int> currRow = matrix[row];
            sort(begin(currRow), end(currRow), greater<int>());
            for(int col = 0; col < n; col++) {
                int base   = (col+1); //iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = currRow[col];
                
                result = max(result, base*height);
            }
            
        }
        
        return result;
    }


int main()
{
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};

    int ans = largestSubmatrix(matrix);
    cout<<"the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally: "<<ans;
}