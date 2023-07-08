#include<iostream>
using namespace std;

int main(){

    int col,row,n;

    cout<<"Enter The Size of Array";
    cin>>n;

    for(row=1;row<=n;row++){
        char ch='A'+ n - row; // find the last value and add with 'A'
        for(col=1;col<=row;col++){
            cout<<ch;
            ch=ch+1;

        }
        cout<<endl;

    }
}
