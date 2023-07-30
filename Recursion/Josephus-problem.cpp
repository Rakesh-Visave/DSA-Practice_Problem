
#include <bits/stdc++.h>
using namespace std;


    int solve(int n, int k)
    {
        if(n == 1)
            return 0;
        
        return (solve(n-1,k) + k) % n;
    }
    int josephus(int n, int k)
    {
       int ans = solve(n,k) +1;
       return ans;
    }



int main()
{
    int n = 3 , k = 2;
    int ans = josephus(n,k);
    cout<<"The safe space in the circle location is at Index: "<<ans;
}