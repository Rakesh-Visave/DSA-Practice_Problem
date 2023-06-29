#include<iostream>
using namespace std;

int findUnique(int arr[], int size){

    int ans = 0;
    for(int i = 0; i<size; i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}



int main(){

    int arr[7] = {2,8,5,8,5,2,9};
    int unique = findUnique(arr,7);
    cout<<"the Unique Element is "<<unique;

}