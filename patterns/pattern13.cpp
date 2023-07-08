#include<iostream>
using namespace std;

int main(){

    int n;
    int row;
    char start = 'A';
    cout<<"Enter the size of Array";
    cin>>n;
    for(row=1; row<=n; row++){
        for(int col=1; col<=n; col++){
            
            cout<<start;
            start = start+1;
        }
        cout<<endl;
    }
}
