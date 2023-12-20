// GFG -- Modified Game of Nim


#include <bits/stdc++.h>
using namespace std;


    int findWinner(int n, int A[]){
         int XOR = 0;
        for(int i = 0; i < n; i++)
            XOR ^= A[i];

        if(XOR == 0)
            return 1;

        return n % 2 == 0 ? 1 : 2;
    }
int main()
{
    int n =3;
    int arr[n] = {3, 3, 2};

    int ans = findWinner(n,arr);

    cout<<" the winner if player 1 starts the game and they both play their best: "<<ans;

}