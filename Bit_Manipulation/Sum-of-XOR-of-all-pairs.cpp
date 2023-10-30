// GFG --Sum of XOR of all pairs


#include <bits/stdc++.h>
using namespace std;


    long long int sumXOR(int arr[], int n)
    {
    	 long long int out = 0;
        for (int i = 0; i < 32; ++i) {
            long long int ones = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if ((arr[j] & mask) != 0) {
                    ones++;
                }
            }
            out += (ones * (n - ones) * mask);
        }
        return out;
    }

int main()
{
    int n = 3;
    int arr[n] = {7,3,5};

    long long int ans = sumXOR(arr,n);

    cout<<"All possible pairs and there Xor Value are: "<<ans;
}