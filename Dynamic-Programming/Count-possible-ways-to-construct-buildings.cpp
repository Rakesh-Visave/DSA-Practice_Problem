// GFG -- Count possible ways to construct buildings

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

	int mod = 1e9 + 7;
	int TotalWays(int N)
	{
	   long long curr, prev, next;
        curr = prev = 1;
        for (int i = 1; i <= N; ++i) {
            next = (curr + prev) % mod;
            prev = curr;
            curr = next;
        }

        return (curr * curr) % mod;
	}


int main()
{
    int n = 1;

    int ans = TotalWays(n);

    cout<<"the total number of ways to construct buildings in these plots: "<<ans;
}