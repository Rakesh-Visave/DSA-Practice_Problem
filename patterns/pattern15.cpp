#include<iostream>
using namespace std;

int main(){

    int n;
    int row;
    cout<<"Enter the size of Array";
    cin>>n;
    for(row=1; row<=n; row++){
        for(int col=1; col<=n; col++){
            char ch = 'A'+row+col-2;
            cout<<ch;

            
            
        }
        cout<<endl;
    }
}

