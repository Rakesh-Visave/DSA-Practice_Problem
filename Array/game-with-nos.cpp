// GEEK-FOR-GEEKS -- Game with nos
#include<bits/stdc++.h>
using namespace std;

void game_with_number(int arr[], int n);


void game_with_number(int arr[], int n)
{
    
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i]^arr[i+1];
    }
   
}


int main()
{
    int arr[5] = {10, 11, 1, 2, 3};

    game_with_number(arr,5);

    cout<<"After XOR operation the Array Element is: ";
    for(int i = 0; i < 5; i++)
    {
        cout<<" "<<arr[i];
    }
    
}
