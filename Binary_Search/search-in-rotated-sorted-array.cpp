#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int>arr, int n) {

    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while (s < e) {

      if (arr[mid] >= arr[0]) 
          s = mid + 1;
      else
            e =  mid;
        mid = s+(e-s)/2;
    }
    return s;
}

int binarySearch(vector<int> arr, int start,int end, int k) {
    int s = start;
    int e = end;
    int mid = s +(e-s)/2;

    while (s <= e) {
      if (arr[mid] == k) 
        return mid;
    else if(k > arr[mid])
        s = mid+1;
    else
        e = mid-1;
    
    mid = s+(e-s)/2;

    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1])
        return binarySearch(arr,pivot,n-1,k);
    else
        return binarySearch(arr,0,pivot-1,k);
}


int main()
{
    vector<int> arr = {1,3,5,7,8};
    int s = search(arr,5,7);

    cout<<s;
}