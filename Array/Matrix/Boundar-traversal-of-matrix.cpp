

#include <bits/stdc++.h> 
using namespace std; 

    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> out;
       int i = 0, j = 0;
       for(; j < m;++j) out.push_back(matrix[i][j]);
       ++i; --j; 
       if(n > 1){
           for(; i < n;++i) out.push_back(matrix[i][j]);
           --i; --j;
            if(m > 1){
                for(; j >= 0;--j) out.push_back(matrix[i][j]);
                --i; ++j;
                for(; i > 0;--i) out.push_back(matrix[i][j]);
            }
       }
       return out;    
    }

int main()
{
    vector<vector<int>> matrix =  {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15,16}};

    int n = 4; 
    int m = 4;

    vector<int> ans = boundaryTraversal(matrix,n,m);

    cout<<"The boundary traversal is:";
    for(int i : ans)
        cout<<" "<<i;
    
    
}