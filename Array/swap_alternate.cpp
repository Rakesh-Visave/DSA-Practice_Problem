#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size){

    for(int i = 0; i<size; i+=2)
    {
        if(i+1 < size)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i] <<" ";
    }
} 

int main()
{
    int a[5] = {2,7,4,9,5};

    swapAlternate(a,5);
    printArray(a,5);
    
}