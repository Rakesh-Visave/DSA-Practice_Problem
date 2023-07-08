#include<iostream>
using namespace std;

int main(){

    int row,col,n;
    cout<<"Enter the size of Array";
    cin>>n;

    for(row=1;row<=n;row++){
        // to print a space 
      int space =n-row;
      while(space){
        cout<<" ";
        space = space-1;
      }
        for(col=1;col<=row;col++){
            //print *
            cout<<"*";
        }
        cout<<endl;
    


    }
}