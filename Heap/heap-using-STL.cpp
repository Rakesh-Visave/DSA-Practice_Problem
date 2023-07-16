#include<iostream>
#include<queue>
using namespace std;

int main()
{
    cout<<"The Max heap is: ";
    priority_queue<int> pd;

    pd.push(5);
    pd.push(10);
    pd.push(4);
    pd.push(2);

    cout<<"The Element at Top : "<<pd.top()<<endl;

    pd.pop();

    cout<<"The size of Heap is: "<<pd.size()<<endl;

    if(pd.empty())
        cout<<"Heap is empty"<<endl;
    else    
        cout<<"Heap is not Empty"<<endl;

    cout<<endl<<endl<<endl;
    cout<<"The Min heap is: ";
    priority_queue<int,vector<int>, greater<int>> p;

    p.push(5);
    p.push(10);
    p.push(4);
    p.push(2);

    cout<<"The Element at Top : "<<p.top()<<endl;

    p.pop();

    cout<<"The size of Heap is: "<<p.size()<<endl;

    if(p.empty())
        cout<<"Heap is empty"<<endl;
    else    
        cout<<"Heap is not Empty"<<endl;

}