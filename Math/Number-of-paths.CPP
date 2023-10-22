//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 


     int mod = 1e9 + 7;

    long long modInv(long long a, long long b) {
        return 1 < a ? b - modInv(b % a, a) * b / a : 1;
    }
    long long  numberOfPaths(int M, int N)
    {
       long long out = 1;

        for (int i = 0; i < M - 1; i++) {
            long long inverse = modInv(i + 1, mod);
            out = (out * (i + N)) % mod;
            out = (out * inverse) % mod;
        }

        return out;
    }

int main()
{
    int m = 3;
    int n = 3;

    long long ans = modInv(m,n);
    cout<<"The count  of all the possible paths from top left to bottom right of an MxN is:"<<ans;
}