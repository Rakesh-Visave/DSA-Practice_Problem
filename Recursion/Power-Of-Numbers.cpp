// GFG -- Power Of Numbers

#include <bits/stdc++.h>
using namespace std;

    long long power(int N,int R)
    {
       int mod = 1e9+7;
       if(R == 0)   
            return 1;
        if(R==1)
            return N;
    
        long long int ans = power(N,R/2);
        

        if(R & 1)
        {
            // b is odd number
            return (N%mod * ans%mod *ans%mod) % mod;
        }
        else   
        { 
            // b is even number
            return (ans%mod * ans%mod)%mod;
        }
    }

int main()
{
    int number = 11;
    int Reverse = 11;

    long long int ans =  power(number,Reverse);
    cout<<"The Answer is: "<<ans;
}