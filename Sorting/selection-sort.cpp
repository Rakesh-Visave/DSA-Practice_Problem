#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

void selectionSort(vector<int>& arr, int n);

void selectionSort(vector<int>& arr, int n)
{
  for (int i = 0; i < n; i++) {
      int minIndex = i;
      for (int j = i+1; j < n; j++) {
        if (arr[j] < arr[minIndex])
            minIndex = j;
        
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main()
{
    vector<int> arr = {1,3,5,7,2};
    int n = 5;
    selectionSort(arr,n);

    cout<<"The Sorted Array using Selection sort is: ";
    for(int i = 0 ;i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}