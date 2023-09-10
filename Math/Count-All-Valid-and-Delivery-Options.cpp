// LEETCODE -- 1359. Count All Valid Pickup and Delivery Options        

#include<iostream>
using namespace std;

int M = 1e9+7;
    int countOrders(int n) {
        if(n == 1)
            return 1;

        long long int result = 1;
        for(int i = 2; i<=n; i++)
        {
            int spaces = (i-1)*2 + 1;
            int temp = spaces * (spaces+1) / 2;

            result *= temp;
            result %= M;
        }
        return result;
    }

int main()
{
    int n = 3;
    int ans = countOrders(n);
    cout<<"all valid pickup/delivery possible sequences is: "<<ans;


}
