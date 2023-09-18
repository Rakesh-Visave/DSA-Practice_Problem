
#include<bits/stdc++.h>
using namespace std;

    bool isPowerofTwo(long long n){
        
        // if(n == 0)
        //     return false;
        
        // if( (n & (n-1)) == 0)
        //     return true;
        
        // return false;
        
        return n && ((n & (n - 1)) == 0);
        
    }

int main()
{
    long long n = 98;

    bool ans = isPowerofTwo(n);
    if(ans)
        cout<<"This Number is Power of 2.";
    else
        cout<<"This Number is Not Power of 2.";
        
}