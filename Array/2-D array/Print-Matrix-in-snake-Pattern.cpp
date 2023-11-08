// GFG -- Print Matrix in snake Pattern


#include <bits/stdc++.h> 
using namespace std; 


    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        bool toggle = false;
        vector<int> out;
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            if (toggle) {
                for (int j = n - 1; j >= 0; --j) {
                    out.push_back(matrix[i][j]);
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    out.push_back(matrix[i][j]);
                }
            }
            toggle = !toggle;
        }
        return out;
    }


int main()
{
    vector<vector<int>> matrix = {{45, 48, 54},
             {21, 89, 87},
             {70, 78, 15}};
    
    vector<int> ans = snakePattern(matrix);
    cout<<"Snake Patter of Given matrix is:";
    for(int i : ans)
        cout<<" "<<i;

}