// CODESTUDIO -- Reverse The Array

#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse (vector<int> arr)
{
    int s = 0;
    int e = arr.size()-1;

    while(s <= e )
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;

}

int main()
{
    vector<int> arr = {1,3,5,6,8};

    vector<int> rev  = reverse(arr);
    cout<<"The reverse Array is ";
    for(int i : rev)
    {
        cout<<i<<" ";
    }


}