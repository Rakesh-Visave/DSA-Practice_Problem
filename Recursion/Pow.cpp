// LEETCODE -- 50. Pow(x, n)

#include<iostream>
using namespace std;
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        long long exp = n; // Cast n to long long to handle the minimum value case

        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;
            }
            x *= x;
            exp /= 2;
        }

        return result;
    }

int main()
{
    double x = 12.0;
    int n = 2;

    double ans = myPow(x,n);
    cout<<"The Answer is: "<<ans;
}
