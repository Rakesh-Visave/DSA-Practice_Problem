
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, 0);
        int out = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2)
                dp[i] = dp[i - 2];
            if (i >= 3)
                dp[i] = max(dp[i], dp[i - 3]);

            dp[i] += arr[i];
            out = max(out, dp[i]);
        }
        
        return out;
    }
int main()
{
    int arr[5] = {6,5,5,7,4};
    int n = 5;

    int ans  = FindMaxSum(arr,n);
    cout<<"Maximum amount he can get by looting 1st, 3rd and 5th house. Which is."<<ans;
}