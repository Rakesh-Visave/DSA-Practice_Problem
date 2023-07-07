#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    if(size == 0)
        return false;
    if(arr[0] == key)
        return true;
    else 
    {
        int remainingPart = linearSearch(arr+1, size-1,key);
        return remainingPart;
    }
}


int main()
{
    int arr[5] = {2,5,7,8,9};
    int key = 10;

    bool ans = linearSearch(arr,5,key);

    if(ans)
        cout<<"The Key is Found";
    else    
        cout<<"The key is not Found";
}