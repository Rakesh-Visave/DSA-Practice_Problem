
#include<bits/stdc++.h>
using namespace std;

    unsigned int getFirstSetBit(int n)
    {
        int cnt = 1;
        while(n > 0)
        {
            if(n&1)
                return cnt;
            
            n >>= 1;
            cnt++;
        }
        return 0;
    }

int main()
{
    int n = 18;
    unsigned int ans = getFirstSetBit(n);
    cout<<"the position of first set bit found from the right side in the binary representation of the number: "<<ans;
}