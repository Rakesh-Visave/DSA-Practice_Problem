#include<iostream>
using namespace std;

int main(){

    int n;
    int count =1;
    cout<<"Enter the size of Array";
    cin>>n;
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            cout<<count<<" ";
            count=count+1;
        }
        cout<<endl;
    }
}
