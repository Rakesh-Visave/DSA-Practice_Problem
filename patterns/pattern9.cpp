#include<iostream>
using namespace std;

int main(){

    int n;
    int row;
    int count =1;
    int value;
    cout<<"Enter the size of Array";
    cin>>n;
    for(row=1; row<=n; row++){
        value=row;
        for(int col=1; col<=row; col++){

            cout<<value;
            value=value+1;
        }
        cout<<endl;
    }
}
