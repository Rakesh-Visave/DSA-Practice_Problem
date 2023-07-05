#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

void bubbleSort(vector<int>& arr, int n);

void bubbleSort(vector<int> &arr, int n) {

    bool swapped = false;
  for (int i = 1; i < n; i++) 
  {
    for (int j = 0; j < n - i; j++)
    {
      if (arr[j] > arr[j + 1]) 
      {
          swap(arr[j],arr[j+1]);
          swapped = true;
      }
    }
    if(swapped == false)
    {
        break;
    }
  }

}


int main()
{
    vector<int> arr = {1,3,5,7,2};
    int n = 5;
    bubbleSort(arr,n);

    cout<<"The Sorted Array using Bubble sort is: ";
    for(int i = 0 ;i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}