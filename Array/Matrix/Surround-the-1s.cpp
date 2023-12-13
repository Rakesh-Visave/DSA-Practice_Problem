
#include<bits/stdc++.h>
using namespace std;

    int dx[8]   = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
    int dy[8]   = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
    
    bool isValid(int &ii, int jj, int &n, int &m){
        return ii<n && ii>=0 && jj<m && jj>=0;
    }
    int Count(vector<vector<int> >& matrix) {
          int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i<n;++i){
            for(int j = 0; j<m; ++j){
                if(matrix[i][j]){
                    int c = 0;
                    for(int k = 0; k<8;++k){
                        int ii = dx[k] + i;
                        int jj = dy[k] + j;
                        if(isValid(ii, jj , n ,m) && matrix[ii][jj] == 0)
                            ++c;
                    }
                    if(c && c%2 == 0)
                        ++cnt;
                }
            }
        }
        
        return cnt;
    }


int main()
{
    vector<vector<int>> matrix = {{1, 0, 0}, 
          {1, 1, 0}, 
          {0, 1, 0}};
        
    int ans = Count(matrix);
    cout<<"Ans is: "<<ans;
}