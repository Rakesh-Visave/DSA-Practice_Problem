
#include <bits/stdc++.h>
using namespace std;

  long long findMinDiff(vector<long long> a, long long n, long long m){
    
    long long int minDiff = INT_MAX;
    sort(a.begin(),a.end());
    for(int i = 0; i+m-1 < n; i++)
    {
        long long diff = a[i+m-1] - a[i];
        minDiff = min(minDiff,diff);
    }
    return minDiff;
    
    }   

int main()
{
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = 8;
    long long m = 5;

    int ans = findMinDiff(a,n,m);
    cout<<"The minimum difference between maximum chocolates and minimum chocolates is: "<<ans;
}