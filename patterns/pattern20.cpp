#include <iostream>
using namespace std;

int main() {
  int n,row,col;
  cout<<"Enter the Size of Array";
  cin>>n;
  for (int row = 0; row < n; row++) {
        // print spaces
        for (int col = 0; col < row; col++) {
            cout << " ";
        }
        
        // print stars
        for (int col = n; col > row; col--) {
            cout << "*";
        }
        
        cout << "\n";
  }
  return 0;
}