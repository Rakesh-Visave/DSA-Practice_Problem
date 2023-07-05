#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place a pivot element at right place
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex],arr[s]);

    // here we arrange all elemenet which is element < pivot <element 
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
    {
        return;
    }

    // funtion for partition.  align a pivot element at right place
    int p = partition(arr, s, e);

    // for sort left part
    quickSort(arr,s,p-1);

    // for sort right part
    quickSort(arr,p+1,e);
}


int main()
{
    int arr[6] = {3,4,2,6,1,10};
    int n = 6;

    quickSort(arr, 0, n-1);
    cout<<"The Sorted array is: ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}