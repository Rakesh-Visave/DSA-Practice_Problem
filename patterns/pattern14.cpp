#include<iostream>
using namespace std;

int main(){

    int n;
    int row;
    cout<<"Enter the size of Array";
    cin>>n;
    for(row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            char ch = 'A'+row-1;
            cout<<ch;

            
            
        }
        cout<<endl;
    }
}
