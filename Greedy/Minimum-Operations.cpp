// GFG -- Minimum Operations

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


    int minOperation(int n)
    {
      int out = -1;
        while(n){
            if(n%2)
                ++out;
            n /= 2;
            ++out;
        }
        
        return out;
    }

int main()
{
    int n = 8;
    int ans = minOperation(n);
    cout<<". Find the minimum number of operations required to reach N starting from 0:"<<ans;
}