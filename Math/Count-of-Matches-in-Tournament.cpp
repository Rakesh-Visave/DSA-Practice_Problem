// LEETCODE -- 1688.Count of Matches in Tournament

#include<iostream>
using namespace std;


    int numberOfMatches(int n) {
        int result = 0;
        
        while(n > 1) {
            if(n%2 == 0) {
                result += n/2;
                n /= 2;
            } else {
                result += (n-1)/2;
                n = ((n-1)/2) + 1;
            }
        }
        
        return result;
        
    }


int main()
{
    int n = 7;
    int ans = numberOfMatches(n);

    cout<<"the number of matches played in the tournament until a winner is decided: "<<ans;
}