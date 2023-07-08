#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the Size of Array";
    cin>>n;
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++)
        {
            cout<<row;
        }
        cout<<endl;
    }
}