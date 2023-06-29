#include<iostream>
using namespace std;

bool isPresent(int arr[][4],int target , int row,int col)
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(target == arr[i][j])
            {
                return 1;
            }
        }
    }
    return 0;

}

int main()
{
    int arr[3][4];
    cout<<"Enter Array Element: ";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Your array Element is: "<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter the Element you want to found: ";
    cin>>target;

    if(isPresent(arr, target, 3, 4))
    {
        cout<<"Element is Found...";
    }
    else
    {
        cout<<"Element is not found";
    }

}