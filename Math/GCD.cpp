#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0)
        return b;

    if(b == 0)
        return a;
    
    while(a != b)
    {
        if(a > b)
            a = a-b;
        else
            b = a-b;
    }
    return a;
}



int main()
{
    int a,b;
    cout<<"Enter the first number: ";
    cin>>a;

    cout<<"Enter the second number: ";
    cin>>b;

    int ans = gcd(a,b);

    cout<<"The Greatest Comman diviser is: "<<ans;
}