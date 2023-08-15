
#include<bits/stdc++.h>
using namespace std;

    int maxOnes(int a[], int n)
    {
        int zero = 0, one = 0, max_flips = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0)
                zero++;
            else{
                zero--;
                one++;
            }

            if (zero < 0)
                zero = 0;

            max_flips = max(zero, max_flips);
        }
        return max_flips + one;
    }

int main()
{
    int a[5] = {1, 0, 0, 1, 0};
    int n = 5;

    int ans = maxOnes(a,n);

    cout<<"answer is: "<<ans;
}