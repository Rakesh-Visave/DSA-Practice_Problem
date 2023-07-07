// CODESSTUDIO -- Count Ways To Reach The N-th Stairs

#include <bits/stdc++.h> 
using namespace std;
int countDistinctWays(int nStairs) {
    if(nStairs <0)
        return 0;
    if( nStairs == 0)
        return 1;
    
    int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2)  ;
    return ans;
}

int main()
{
    int nstrairs = 3;
    int ans = countDistinctWays(nstrairs);

    cout<<"the number of Distinct ways we can climb 0th to nth step is: "<<ans;

}