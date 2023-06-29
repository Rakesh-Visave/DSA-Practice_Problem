#include<iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++) {
      
          ans = arr[i]^ans;
      }
      return ans;
}

int main()
{
    int arr[5] = {1,2,3,2,1};

    int ans = findUnique(arr,5);

    cout<<"Unique Element of this Array is "<<ans;
}