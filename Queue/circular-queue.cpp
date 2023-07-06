#include <bits/stdc++.h> 
#include<queue>
#include<iostream>
using namespace std;


class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
    public:

    CircularQueue(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;

    }

    bool enqueue(int value){

        // check queue is full
        if((front == 0 && rear == size-1) || (rear == (front -1)%(size-1) ) )
            return false;

        // insertd element is first 
        if(front == -1)
            front = rear = 0;

        // create a cyclic nature
        else if(rear == size-1 && front != 0)
            rear = 0;
        
        // Normal Case
        else   
            rear++;

     arr[rear] = value;
     return true;
    }

    int dequeue(){
        // check empty
        if(front == -1)
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        // single value in queue
        if(front == rear)
            front = rear = -1;

        // maintain cylic nature
        else if(front == size-1)
            front = 0;

        // normal flow
        else  
            front++;

    return ans;  
    }

    bool isEmpty()
    {
        if(front == -1)
            return true;
        return false;
    }


};

int main()
{
    CircularQueue a(5);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(40);
    a.enqueue(50);
   

    a.dequeue();
     a.enqueue(60);



    cout<<"After Queue operation the queue will be: ";
   while(!a.isEmpty())
   {
        cout<<" "<<    a.dequeue();
   }

   a.isEmpty();
}