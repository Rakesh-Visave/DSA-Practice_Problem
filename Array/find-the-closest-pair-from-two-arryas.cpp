// GFG -- Find the Closest pair from two Arrays


#include <bits/stdc++.h>
using namespace std;

    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
         vector<int> out;
        int nin = INT_MAX;
        
        int a = 0, b = m - 1;
        while(a < n && b >= 0){
            int sum = arr[a] + brr[b];
            if(abs(sum - x) < nin){
                out = {arr[a], brr[b]};
                nin = abs(sum - x);
            }
            if(sum > x)
                --b;
            else
                ++a;
        }
        return out;
    }


int main()
{
    int n =4, m = 5;
    
    int arr[n] = {1,4,5,7};
    int brr[m] = {10,20,30,40};

    int x = 32;

    vector<int> ans = printClosest(arr,brr,n,m,x);
    cout<<" The CLosest Pair whose sum is closest to x : ";
    for(int i : ans)
    {
        cout<<i <<" ";
    }


}