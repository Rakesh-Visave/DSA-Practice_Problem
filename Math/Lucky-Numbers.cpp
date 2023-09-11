// GFG -- Lucky Numbers
#include<iostream>
using namespace std;

    bool isLucky(int n) {
       
       for(int i = 2; i<=n; i++)
       {
           if(n % i == 0)
                return false;
            
            n = n- n/i;
            
            
        }
        return true;
    }

int main()
{
    int n = 19;
    bool ans = isLucky(n);
    if(ans)
        cout<<"The Number is Lucky Number.";
    else    
        cout<<"The  Number is Not Lucky Number.";
}