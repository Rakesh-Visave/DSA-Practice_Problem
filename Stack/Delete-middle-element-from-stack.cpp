// CODESTUDIO -- Delete middle element from stack

#include <bits/stdc++.h> 
#include<stack>
#include<iostream>
using namespace std;

void solve(stack<int>&inputStack, int size,int count)
{
   if(count == size/2)
   {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();
   
   solve(inputStack,size,count+1);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
  int count = 0;
  solve(inputStack,N,count);
   
}

int main()
{
    stack<int> s;
    int n = 5;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    deleteMiddle(s,n);
    
    cout<<"After deleting middle element from stack: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    

}