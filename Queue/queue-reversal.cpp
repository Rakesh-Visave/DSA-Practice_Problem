// GFG -- queue reversal
#include<bits/stdc++.h>
#include<queue>
using namespace std;


    queue<int> rev(queue<int> q)
    {
       stack<int> s;
       
    //   putting Queue element into the stack
       while(!q.empty())
       {
           int element = q.front();
           q.pop();
           s.push(element);
           
       }
    //     putting stack element into the queue
       while(!s.empty())
       {
           int element = s.top();
           s.pop();
           q.push(element);
       }
     return q;
    }
    

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> ans  = rev(q);

    cout<<"The Reverse Queue is: "<<endl;
    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }

}