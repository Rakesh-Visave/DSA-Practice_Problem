// CODESTUDIO - First and Last Position of an Element In Sorted Array

#include<iostream>
using namespace std;

int firstOcc( int arr[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;

    while(s<=e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            e = mid-1;
        }

        else if(key >arr[mid])
            s = mid + 1;

        else
            e = mid-1;

        mid = s + (e-s) / 2;

    }
    return ans;
}
int lastOcc( int arr[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;

    while(s<=e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }

        else if(key >arr[mid])
            s = mid + 1;

        else
            e = mid-1;

        mid = s + (e-s) / 2;

    }
    return ans;
}


int main()
{
    int arr[6]  = {10,20,20,20,40,10};
    int first = firstOcc(arr,6,20);
    int last  = lastOcc(arr,6,20);

    cout<<"The First Occurence is "<<first<<endl;
    cout<<"The Last Occurence is  "<<last;

}