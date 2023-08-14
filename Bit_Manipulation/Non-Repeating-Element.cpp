
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
    int firstNonRepeating(int arr[], int n) 
    { 
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i= 0; i<n; i++)
        {
            int key = arr[i];
            auto temp = mp.find(key);
            if (temp->second == 1)
                return arr[i];
                
        }
        return 0;
        
    } 
  
int main()
{
    int arr[5] = {-1, 2, -1, 3, 2};
    int n = 5;

    int ans =  firstNonRepeating(arr,n);
    cout<<"The First non reapting Number is: "<<ans;
}