// LEETCODE -- 1486. XOR Operation in an Array

#include<iostream>
using namespace std;


    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
           int element = start +2 *i;
           ans = ans ^ element;

        }
    
        return ans;
    }

int main()
{
    int n = 5;
    int start = 0;

    int ans = xorOperation(n,start);
    cout<<" XOR of all elements: "<<ans;
}