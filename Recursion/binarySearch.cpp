// CODESTUDIO -- Binary Search

#include<iostream>
using namespace std;

void print(int arr[], int s, int e)
{   
    cout<<endl;
    for(int i = s; i<=e; i++)
    {
        cout<<arr[i]<<" ";
    }
}
bool binarySearch(int arr[], int s, int e, int key)
{
    print(arr,s,e);// printing the array to check recursion calls
    if(s > e)
        return false;

    int mid = s + (e-s)/2;

    cout<<"The mid is: "<<arr[mid];
    if(arr[mid] == key)
        return true;
    
    if(key > arr[mid])
        return binarySearch(arr,mid+1,e,key);
    else
        return binarySearch(arr,s,mid-1,key);
}

int main()
{
    int arr[6] = {2,4,6,8,10,12};
    int key = 12;

    bool ans = binarySearch(arr,0,5,key);
    if(ans)
        cout<<" key is Presnt";
    else
        cout<<"key is Absent";
}