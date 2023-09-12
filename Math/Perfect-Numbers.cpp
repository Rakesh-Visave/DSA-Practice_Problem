
#include <bits/stdc++.h>
using namespace std;


    int isPerfectNumber(long long N) {
        if(N == 1)
            return 0;
        long long sum = 1;
        for(int i = 2; i<=sqrt(N ); ++i){
            if(N%i == 0){
                sum += i;
                if(N%i != i)
                    sum += N/i;
            }
        }
        return sum == N;
    }


int main()
{
    long long int N = 6;
    int ans = isPerfectNumber(N);

    cout<<"The Answer is: "<<ans;
    
}