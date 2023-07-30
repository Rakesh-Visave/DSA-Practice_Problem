//  LEETCODE -- 1823.Find the Winner of the Circular Game

#include<iostream>
using namespace std;

    int solve(int n , int k )
    {
        if(n == 1)
            return 0;
        return (solve(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
     int ans = solve(n,k) + 1;
     return ans;    
    }

int main()
{
    int n = 5 ,k = 2;
    int ans = findTheWinner(n,k);
    cout<<"The winner of the game is at index: "<<ans;
}
