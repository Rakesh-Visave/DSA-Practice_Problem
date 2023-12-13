// LEETCODE -- 867.Transpose Matrix

#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }


void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example matrix array
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the matrix
    std::cout << "Matrix:" << std::endl;
    printMatrix(matrix);

    return 0;
}
