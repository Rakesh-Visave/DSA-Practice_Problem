#include<iostream>
#include<vector>
using namespace std;

int findPivot(int arr[],int n)
{
    int s =  0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while (s<e){

       if(arr[mid] >= arr[0])
            s = mid + 1;
            
        else
            e = mid;
        
        mid = s + (e-s)/2;
    }
    return s;
     
}

int main()
{
    int arr[5] = {3,10,17,8,2};

    int pivotElement = findPivot(arr,5);

    cout<<"The Pivot Element of the Array is : "<<pivotElement;
}