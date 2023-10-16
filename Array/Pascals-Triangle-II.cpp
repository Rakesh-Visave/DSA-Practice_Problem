#include<iostream>
#include<vector>
using namespace std;

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                result[i][j] = result[i-1][j] + result[i-1][j-1];
                
            }
            
            if(i == rowIndex) //Just return when you find rowIndex
                return result[i];
            
        }
        
        return {};
    }

int main()
{
    int rowIndex = 3;
    vector<int> ans = getRow(rowIndex);
    cout<<" Pascal Traingle is: ";
    for(int  i : ans)
    {
        cout<<i <<" ";
    }

}