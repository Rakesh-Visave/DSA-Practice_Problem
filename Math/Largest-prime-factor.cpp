
#include<bits/stdc++.h> 
using namespace std;

    long long int largestPrimeFactor(int N){
        vector<int> primeFactor;
        for(int i = 2; i<=N; i++)
        {
            while(N % i == 0)
            {
                primeFactor.push_back(i);
                N = N/i;
                
            }
        }
        int maxi = 0;
        for(auto i : primeFactor)
        {
            maxi = max(maxi,i);
        }
        return maxi;
    }

int main()
{
    int N = 5;
    long long int ans = largestPrimeFactor(N);

    cout<<" largest prime factor of that number: "<<ans;

}