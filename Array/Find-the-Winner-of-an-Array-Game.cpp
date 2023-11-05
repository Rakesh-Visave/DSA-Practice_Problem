// LEETCODE -- 1535.Find the Winner of an Array Game


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


    int getWinner(vector<int>& arr, int k) {
          int n = arr.size();
        int maxEl = *max_element(begin(arr), end(arr));
        
        if(k >= n)
            return maxEl;
        
        
        int winner     = arr[0];
        int wins       = 0;
        
        for(int i = 1; i<n; i++) {
            
            if(winner > arr[i]) {
                wins++;
            } else {
                winner = arr[i];
                wins   = 1;
            }
            
            if(wins == k || winner == maxEl) {
                return winner;
            }
            
        }
        
        return winner;
    }


int main()
{
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;

    int ans = getWinner(arr,k);

    cout<<ans<<" will win the first k rounds consecutively.";
}