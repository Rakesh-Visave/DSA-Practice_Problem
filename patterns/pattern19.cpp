#include<iostream>
using namespace std;

int main(){

    int col,row,n;

    cout<<"Enter The Size of Array";
    cin>>n;

    for(row=1;row<=n;row++){
        int star = n-row+1;
        for(col=1;col<=n;col++){
                while(star)
                {
                    cout<<"*";
                    star = star-1;
                }
        
        }
        cout<<endl;
    }
}
