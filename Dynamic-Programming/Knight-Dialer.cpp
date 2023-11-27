// LEETCODE -- 935.Knight Dialer

#include<iostream>
#include<vector>
using namespace std;

    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int knightDialer(int n) {
         int result = 0;
        
        //t[i][j] = number of ways to form a number of length i when I am currently at cell j
        
        vector<vector<int>> t(n, vector<int>(10));
        for(int cell = 0; cell < 10; cell++) {
            t[0][cell] = 1; //for n == 0, we always returned 1
        }
        
        for(int i = 1; i < n; i++) { //This is length of number 
            
            for(int cell = 0; cell <= 9; cell++) {    
                int ans = 0;
                for(int &nextCell : adj[cell]) {
                    
                    ans = (ans + t[i-1][nextCell]) % M;
                    
                }
                t[i][cell] = ans;
                
            }
            
        }
        
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + t[n-1][cell]) % M;
        }
        
        return result;
        
    }


int main()
{
    int n = 1;
    int ans = knightDialer(n);

    cout<<"We need to dial a number of length n , so placing the knight over any numeric cell of the "<<ans <<" cells is sufficient.";
}