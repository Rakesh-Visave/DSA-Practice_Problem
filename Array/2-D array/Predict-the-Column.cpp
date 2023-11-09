// GFG -- Predict the Column

#include <bits/stdc++.h>
using namespace std;


    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        int maxZeros = 0;
        int columnIdx = -1;
        
        for (int j = 0; j < N; j++) {
            int zerosCount = 0;
            for (int i = 0; i < N; i++) {
                if (arr[i][j] == 0) {
                    zerosCount++;
                }
            }
            
            if (zerosCount > maxZeros) {
                maxZeros = zerosCount;
                columnIdx = j;
            }
        }
        
        return columnIdx;
        
    }

int main()
{
    vector<vector<int>> arr= {{0, 0, 0},
          {1, 0, 1},
          {0, 1, 1}};

    int n = 3;

    int ans = columnWithMaxZeros(arr,n);
    cout<<"Answer is: "<<ans;
}