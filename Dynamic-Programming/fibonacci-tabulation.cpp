#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cout<<"Enter Element to find fibonacci number: ";
    cin>>n;
    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;   
       
    for(int i =2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout<< "fibonacci number at "<<n<<" th position is: "<<dp[n];
    return 0;
}