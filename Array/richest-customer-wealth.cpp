// Leetcode1672. Richest Customer Wealth

#include<vector>
using namespace std;
#include<iostream>

    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = -99999;

        for(int i = 0; i < accounts.size(); i++){
            int sum = 0;

            for(int j = 0; j < accounts[i].size(); j++){
                sum += accounts[i][j];
            }
         maxi = max(maxi,sum);

        }
    return maxi;                        
    }

int main() {


    vector<vector<int>> accounts = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int maxWealth = maximumWealth(accounts);
    cout << "Maximum wealth: " << maxWealth << endl;

    return 0;
}