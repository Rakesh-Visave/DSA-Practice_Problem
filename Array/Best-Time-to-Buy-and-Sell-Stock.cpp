// LEETCODE -- 121. Best Time to Buy and Sell Stock

#include<iostream>
#include<vector>
using namespace std;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i = 0; i<n; i++)
        {
            int diff = prices[i] - mini;
            profit = max(profit ,diff);
            mini = min(mini,prices[i]);
        }
        return profit;
    }

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout<<"The Maximum profit we can achive from this transaction is: "<<ans;

 
}
