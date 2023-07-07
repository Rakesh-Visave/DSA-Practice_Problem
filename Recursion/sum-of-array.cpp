#include<iostream>
using namespace std;


int sumArray(int arr[] , int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return arr[0];
    
    int remainingPart = sumArray(arr+1 , n-1);
    int sum = arr[0]+remainingPart;
    return sum;
}

int main()
{
    int arr[6] = {1,2,3,4,5,6};

    int sum = sumArray(arr ,6);
    cout<<sum;

}