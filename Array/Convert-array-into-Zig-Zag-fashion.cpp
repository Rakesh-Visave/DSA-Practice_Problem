
#include <bits/stdc++.h>
using namespace std;

    void zigZag(int arr[], int n) {
        
        bool flag = true;
        for(int i = 0; i<n-1; i++)
        {
            
            // "<" relation is expeted
            if(flag) 
            {
                // if not < less than then we need to swap
                if(arr[i] > arr[i+1])
                    swap(arr[i],arr[i+1]);
            }
            // ">" relation is exptected
            else
            {
            
                // if not > then we need to swap 
                if(arr[i] < arr[i+1])
                    swap(arr[i],arr[i+1]);
            }
            flag = !flag;
        }
    }

int main()
{
    int arr[7] = {4, 3, 7, 8, 6, 2, 1};
    int n = 7;
    zigZag(arr,n);

    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
     
}


