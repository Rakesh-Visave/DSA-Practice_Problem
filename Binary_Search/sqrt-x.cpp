//  LEETCODE -- 69. Sqrt(x)


#include<iostream>
using namespace std;

long long int binarySearch(int n)
{
    int s = 0;
    int e  = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;

    while(s <= e)
    {
        long long int squre  =  mid * mid;
        if(squre == n)
            return mid;
        else if(squre < n)
        {
            ans = mid;
            s = mid +1;
        }
        else
            e = mid - 1;
               
        mid = s+(e-s)/2;
    }   
    return ans;
}

double morePrecision(int n, int temp ,int precision)
{
    double factor = 1;
    double ans = temp;

    for(int i = 0; i<precision; i++)
    {
        factor = factor/10;
        for(double j = ans; j*j < n; j=j+factor)
            ans = j;
    }
    return ans;
}

int main() {
    int x = 37;
    int temp =  binarySearch(x);

    double sqRoot = morePrecision( x,temp ,3);
    cout<<"The Squre Root of given number is: "<<sqRoot;
}

