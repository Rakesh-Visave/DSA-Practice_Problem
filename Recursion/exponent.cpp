#include<iostream>
using namespace std;

int  exponent(int a ,int b)
{
    if(b == 0)   
        return 1;
    if(b==1)
        return a;
    
    int ans = exponent(a,b/2);

    if(b & 1)
    {
        // b is odd number
        return a * ans *ans;
    }
    else   
    { 
    // b is even number
        return ans * ans;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;

    int ans = exponent(a,b);

    cout<<ans;
}