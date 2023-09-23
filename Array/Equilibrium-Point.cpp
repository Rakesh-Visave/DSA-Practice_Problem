
#include <iostream>
using namespace std;

    int equilibriumPoint(long long a[], int n) {
    
        long long sum = 0, preSum = 0;
        for(int i = 0; i < n; ++i)
            sum += a[i];
            
        for(int i = 0; i < n; ++i){
            sum -= a[i];
            if(sum == preSum)
                return i+1;
            preSum += a[i];
        }
        return -1;
    }

int main()
{
    int n  = 5;
    long long a[n] = {1,3,5,2,2} ;

    int ans = equilibriumPoint(a,n);

    cout<<"equilibrium point is at position "<<ans;
}