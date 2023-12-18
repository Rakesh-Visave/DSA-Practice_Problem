// GFG -- Game of XOR


#include <bits/stdc++.h>
using namespace std;


    int gameOfXor(int N , int A[]) {
        if (N % 2 == 0)
            return 0;

        int XOR = 0;
        for (int i = 0; i < N; i += 2)
            XOR ^= A[i];
        return XOR;
    }


int main()
{
    int n = 3;
    int arr[n] = {1,2,3};

    int ans = gameOfXor(n,arr);
    cout<<"the bit-wise XOR of the values of all subarrays of A: "<<ans;
}