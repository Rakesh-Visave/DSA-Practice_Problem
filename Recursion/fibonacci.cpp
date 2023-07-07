// LEETCODE -- 509. Fibonacci Number


#include<iostream>
using namespace std;

    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        int ans = fib(n-1) + fib(n-2);
        return ans;
        
    }
int main()
{
    int n = 3;
    int ans = fib(n);

    cout<<"The nth number value in fibonacii series is: "<<ans;
}