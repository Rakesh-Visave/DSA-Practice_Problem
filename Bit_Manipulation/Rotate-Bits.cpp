//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


        vector <int> rotate (int n, int d)
        {
            int mask_16 = (1<<16) - 1;
            d = d%16;
            
            vector<int> out(2);
            out[0] = (n<<d|(n>>(16-d)));
            out[0] = out[0] & mask_16;  
            
            out[1] = (n>>d|(n<<(16-d)));
            out[1] = out[1] & mask_16;
            
            return out;
        }

int main()
{
    int n = 28;
    int d = 2;

    vector<int> ans = rotate(n,d);
    cout<<"their decimal representation after each of the rotation.";
    for(int i : ans)
    {
        cout<<i<<" "<<endl;
    }
}