#include<iostream>
using namespace std;

    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        while(n%4 == 0){
            n /= 4;
        }
        return n==1;      
    }

int main()
{
    int n  = 16;
    bool ans = isPowerOfFour(n);
    if(ans)
        cout<<"Given number is power of 4.";
    else
        cout<<"Given Number is not Power of 4.";
}