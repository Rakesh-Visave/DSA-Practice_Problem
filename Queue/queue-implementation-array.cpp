#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
class Queue {

    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;

    }

    bool isEmpty() {
      if(rear == qfront)
            return true;
        return false;
    }

    void enqueue(int data) {
        if(rear == size)
        {
            cout<<"The Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear)
            return -1;

        int ans = arr[qfront];
        arr[qfront]  = -1;
        qfront++;

        if(qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if(qfront == rear)
        {
            return -1;
        }
        else   
        { 
            return arr[qfront];    
        }    
    }
};

int main()
{
    Queue a;
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);

    a.dequeue();

    int front = a.front();

   cout<<"The Front is at: " <<front<<"  position "<<endl;

    cout<<"After Queue operation the queue will be: ";
   while(!a.isEmpty())
   {
        cout<<" "<<a.front();
        a.dequeue();
   }

   a.isEmpty();

}