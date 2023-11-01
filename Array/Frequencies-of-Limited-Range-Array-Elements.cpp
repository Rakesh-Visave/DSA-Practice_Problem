// GFG -- Frequencies of Limited Range Array Elements


#include<bits/stdc++.h>
using namespace std; 


    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int offset = P + 1;

        for (auto i : arr) {
            int val = (i - 1) % offset;
            if (val < N) {
                arr[val] += offset;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            arr[i] /= offset;
        }
    }

int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    int n  = 5;
    int p = 5;

    frequencyCount(arr,n,p);

    cout<<"Counting frequencies of each array element and we get Array: ";
    for(int i : arr)
    {
        cout<<i<<" ";
    }   
}