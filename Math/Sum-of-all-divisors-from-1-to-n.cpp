//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

    long long sumOfDivisors(int N)
    {
        long long out = 0;
        for(int i = 1; i<=N;++i){
            out += (N/i) * i;
        }
        return out;
    }

int main()
{
    int n = 4;
    long long ans = sumOfDivisors(n);

    cout<<"Ans is:"<<ans;
}