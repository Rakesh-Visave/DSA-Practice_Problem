#include<iostream>
using namespace std;

bool isSorted(int arr[] , int size)
{
    if(size == 0 || size == 1)
    {
        return true;
    }
    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remaingPart = isSorted(arr+1, size-1);
        return remaingPart;
    }
}


int main()
{
    int arr[5] = {1,3,4,6,7};
    int size = 5;

    bool ans =  isSorted(arr , 5);
    cout<<ans;
}
