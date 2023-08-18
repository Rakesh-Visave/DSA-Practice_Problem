
#include <bits/stdc++.h>
using namespace std;


    vector<int> leaders(int a[], int n){
      vector<int> ans;
       int maxi = INT_MIN;
       for(int i = n-1; i >= 0; i--){
           if(a[i] > maxi)
               ans.push_back(a[i]);

           maxi = max(maxi,a[i]);
           }

        reverse(ans.begin(), ans.end());
        return ans;
        
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