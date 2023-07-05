// GEEKFORGEEKS -- merge sort
// CODESTUDIO -- merge sort

#include<iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s+(e-s)/2;

    int len1 = mid -s +1;
    int len2 = e - mid;

    // create a two array with lenght len1 and len2
    int *first = new int[len1];
    int *second = new int[len2];

    // copy the value of arr array into the two subarrays first and second
    int k = s;
    for(int i = 0; i<len1; i++)
    {
        first[i] = arr[k++];
    }
    // copy in a second array which is start from mid+1
    k = mid+1;
    for(int i = 0; i<len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted array element
    int index1 = 0;
    int index2 = 0;
     k = s;

     while(index1 < len1 && index2 < len2)
     {
        if(first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
            arr[k++] = second[index2++];
     }
     while(index1 < len1)
     {
        arr[k++] = first[index1++];
     }
     while(index2 < len2)
     {
        arr[k++] = second[index2++];
     }
    //  delete the Array for free up the memory space
     delete [] first;
     delete [] second;
    

}

void mergeSort(int arr[], int s, int e)
{
    if(s >= e)
        return;
    
    int mid = s+(e-s)/2;

    // for left part sorting
    mergeSort(arr,s,mid);

    // for right part sorting
    mergeSort(arr,mid+1, e);
    merge(arr,s,e);

}

int main()
{
    int arr[6] = {2,5,3,8,1,11} ;
    int n = 6;

    mergeSort(arr,0,n-1);

    cout<<"The Sorted array is ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}