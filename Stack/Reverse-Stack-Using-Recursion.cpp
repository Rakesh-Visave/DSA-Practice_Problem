#include<iostream>
#include<stack>
using namespace std;

void insertElement(stack<int>& stack, int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }

    int element = stack.top();
    
    stack.pop();
    insertElement(stack,num);
    stack.push(element);
}



void reverseStack(stack<int> &stack) {
    
    if(stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertElement(stack,num);


}

int main()
{
    stack<int> stack;
    stack.push(20);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    reverseStack(stack);

    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
}