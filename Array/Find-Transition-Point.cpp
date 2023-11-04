
#include <bits/stdc++.h>
using namespace std;
   
    
    int transitionPoint(int arr[], int n) {
         int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            
            if (arr[m] < 1)
                l = m + 1;
            else
                r = m;
        }
        
        return arr[l] ? l : -1;
    }


int main()
{

    int n = 5;
    int arr[n] = {0,0,0,1,1};

    int ans = transitionPoint(arr,n);

    cout<<"index "<<ans<<" is the transition point where 1 begins.";
}