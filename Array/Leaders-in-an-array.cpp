
#include <bits/stdc++.h>
using namespace std;


    vector<int> leaders(int a[], int n){
      vector<int> out;
       int nax = -1;
       for(int i = n-1; i >= 0; --i){
           if(nax <= a[i]){
               nax = a[i];
               out.push_back(a[i]);
           }
       }
        reverse(out.begin(), out.end());
        return out;
        
    }

int main()
{
    int a[6] = {6,17,4,3,5,2};
    int n = 6;

    vector<int> ans  = leaders(a,n);
    cout<<"Leader element in the Array will be: ";
    for(auto i : ans)
        cout<<" "<<i;
}