//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

    void booleanMatrix(vector<vector<int> > &matrix)
    {
         int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> r(n, 0), c(m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j]) {
                    r[i] = true;
                    c[j] = true;
                }

        for (int i = 0; i < n; ++i)
            if (r[i])
                for (int j = 0; j < m; ++j)
                    matrix[i][j] = 1;

        for (int j = 0; j < m; ++j)
            if (c[j])
                for (int i = 0; i < n; ++i)
                    matrix[i][j] = 1;
    }

 
int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Original Matrix:\n";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    booleanMatrix(matrix);

    cout << "\nMatrix after conversion:\n";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

