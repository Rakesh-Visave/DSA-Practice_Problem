// LEETCODE -- 62.Unique Paths
#include<iostream>
using namespace std;

    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        
        return uniquePaths(m-1 , n) + uniquePaths(m, n-1);
        
    }

int main()
{
    int m = 3 , n = 7;
    int ans = uniquePaths(m,n);
    cout<<"number of possible unique paths that the robot can take to reach the bottom-right corner: "<<ans;
}