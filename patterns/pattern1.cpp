#include<iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 3;

    cout<<"A &  B is "<< (a&b) <<endl;
    cout<<"A |  B is "<< (a|b) <<endl;
    cout<<"~ A is "<< (~a) <<endl;
    cout<<"A ^  B is "<< (a^b) <<endl;

    cout<<(17 >> 1) <<endl;
    cout<< (17 >> 2) <<endl;

    cout<< (19 << 1) <<endl;
    cout<< (21 << 2) <<endl;
}