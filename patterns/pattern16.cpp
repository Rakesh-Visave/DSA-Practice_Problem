#include<iostream>
using namespace std;

int main(){

    int col,row,n;
    char ch='A';
    cout<<"Enter the Size of Array";
    cin>>n;

    for(row=1;row<=n;row++){
        for(col=1;col<=row;col++){
            cout<<ch;
            ch=ch+1;
            
        }
        cout<<endl;
    }
}