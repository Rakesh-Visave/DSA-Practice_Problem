// LEETCODe -- 2373.Largest Local Values in a Matrix

#include<iostream>
#include<vector>
using namespace std;


    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
      int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int x = i; x <= i + 2; ++x) {
                    for (int y = j; y <= j + 2; ++y) {
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                    }
                }
            }
        }
        return ans;   
    }

int main() {
    // Hardcoded input
    vector<vector<int>> inputGrid = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };

    // Call largestLocal function with the hardcoded input
    vector<vector<int>> result = largestLocal(inputGrid);

    // Print the resulting matrix
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout <<endl;
    }

    return 0;
}