// GFG -- Check if a string is repetition of its substring of k-length

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

	int kSubstrConcat (int n, string s, int k)
	{
	     if (n % k > 0)
            return 0;

        unordered_map<string,int> mp;
        for (int i = 0; i < n / k; ++i)
            ++mp[s.substr(i * k, k)];
        
        int cnt = 0;
        for(auto i : mp)
            cnt += i.second > 1;

        return (mp.size() <= 2 && cnt <= 1);
	}


int main()
{
    int n =4;
    string s = "bdac";

    int k = 2;

    int ans = kSubstrConcat(n,s,k);

    cout<<"Ans is: "<<ans;
}