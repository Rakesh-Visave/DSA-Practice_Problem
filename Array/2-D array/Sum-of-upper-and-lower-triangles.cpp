// GFG -- Sum of upper and lower triangles


#include <bits/stdc++.h> 
using namespace std; 


    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        vector<int> out(2, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i <= j)
                    out[0] += matrix[i][j];
                if (i >= j)
                    out[1] += matrix[i][j];
            }
        }
        return out;
    }

int main()
{
    vector<vector<int>> matrix = {{6, 5, 4},
           {1, 2, 5},
           {7, 9, 7}};

           int n = 3;

    vector<int> ans = sumTriangles(matrix,n);
    cout<<"Sum of Upper and Lower Triangle is :";
    for(int i : ans)
        cout<<" "<<i;

}