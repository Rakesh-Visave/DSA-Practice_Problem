// practice question not in leetcode
#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n)
{
    for(int i = 0; i < n; i = i+2)
    {
        if(arr[i] < n)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++)
    {
        cout<<" " <<arr[i];
    }
}


int main()
{
    int arr[8] = {1,4,6,2,8,5,3,9};

    swapAlternate(arr,8);
    printArray(arr,8);


}