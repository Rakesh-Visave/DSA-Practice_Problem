
#include <bits/stdc++.h>
using namespace std;

	int maxSumIS(int arr[], int n)  
	{  
	   vector<int>dp(arr, arr+n);
        
        for(int i=1;i<n;i++) 
            for(int j=0;j<i;j++) 
                if(arr[j]<arr[i]) 
                    dp[i] = max(dp[i],dp[j]+arr[i]);
                    
        int out=0;
        for(auto i: dp) 
            out = max(out,i);
        return out;
	}  


int main()
{
    int n =5;
    int arr[n] = {1, 101, 2, 3, 100};

    int ans = maxSumIS(arr,n);

    cout<<"The maximum sum of a increasing sequence is: "<<ans;
}