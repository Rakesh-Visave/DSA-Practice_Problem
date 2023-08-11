// GFG -- coin change


#include <bits/stdc++.h>
using namespace std;


    long long int count(int coins[], int N, int sum) {

        long long int dp[N][sum + 1];

        for (int i = 0; i <= sum; ++i)
            dp[0][i] = (i % coins[0] == 0);

        for (int i = 1; i < N; ++i) {
            for (int s = 0; s <= sum; ++s) {
                long long int nottake = dp[i - 1][s];
                long long int take = 0;

                if (s - coins[i] >= 0)
                    take = dp[i][s - coins[i]];

                dp[i][s] = take + nottake;
            }
        }

        return dp[N - 1][sum];
    }

int main()
{
    int coins[3] = {1,2,3};
    int N = 3;
    int sum = 4;

    long long int ans = count(coins,N,sum);

    cout<<"the number of ways you can make sum by using different combinations from coins: "<<ans;
}