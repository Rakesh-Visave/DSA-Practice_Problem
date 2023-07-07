#include<iostream>
using namespace std;

void reachHome(int src , int dest)
{
    cout<<"Source "<<src <<"   Destination "<<dest<<endl;
    if(src == dest)
    {
        cout<<"Home Reached";
        return;
    }
    // src++;
    reachHome(src+1 , dest);
}

int main()
{
    int src = 0;
    int dest = 10;

    reachHome(src , dest);

}