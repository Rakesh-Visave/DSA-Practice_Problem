// CODESTUDIO -- Largest Element in the Array

#include <bits/stdc++.h> 
#include<vector>
#include<iostream>
using namespace std;
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0];

    for(int i = 1; i<n; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

int main()
{
    vector<int> arr = {1,2,6,5,9};
    int n = 5;

    int ans = largestElement(arr,n);
    cout<<"The Largest Element is: "<<ans;

}