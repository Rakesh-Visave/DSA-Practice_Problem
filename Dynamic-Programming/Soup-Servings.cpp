#include<iostream>
#include<vector>
using namespace std;
   
    vector<pair<int,int>> serves = { {100,0}, {75,25}, {50,50}, {25,75}};

    vector<vector<double>> dp;

    double solve(double a, double b)
    {
        if(a <= 0 && b <= 0)
            return 0.5;

        if(a <= 0)
            return 1.0;
        
        if(b <= 0)
            return 0.0;
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        double prob = 0.0;
        for(auto &p : serves)
        {
            int A_taken = p.first;
            int B_taken = p.second;

            prob += solve(a - A_taken, b - B_taken);
        }
        return dp[a][b] = 0.25 * prob; 

    }
    double soupServings(int n) {

        if(n >= 5000)
            return 1;
        dp.resize(n+1, vector<double>(n+1,-1.0));
        return solve(n,n);   
    }

int main()
{
    int n =  50;
    double ans = soupServings(n);

    cout<<"the probability that soup A will be empty first is: "<<ans;
}