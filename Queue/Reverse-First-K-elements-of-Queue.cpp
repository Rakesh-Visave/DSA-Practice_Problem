// GFG -- Reverse First K elements of Queue
#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int>& q, int k) {
    
    stack<int> s;

    // insert 0 to k element in to a stack
    for(int i = 0; i<k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    // put  to k element into queue 
    // here we get reverse order element but at last position
    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    // arrrange element 
    int t = q.size()-k;
    
    while(t--)
    {
        int element = q.front();
        q.pop();
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

    int k = 3;

    queue<int> ans = modifyQueue(q,k);
    cout<<"After Revsering the First to  Kth element  the queue is: "<<endl;
    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
}