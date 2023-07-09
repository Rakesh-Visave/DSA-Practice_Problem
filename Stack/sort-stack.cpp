// CODESTUDIO  -- Sort Stack

#include <bits/stdc++.h> 
#include<stack>
#include<iostream>
using namespace std;

void sortedInsert(stack<int> &stack , int num)
{
	if(stack.empty() || (!stack.empty() && stack.top() < num))
	{
		stack.push(num);
		return;
	}
	int element = stack.top();
	stack.pop();
	sortedInsert(stack ,num);
	stack.push(element);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	sortedInsert(stack,num);
}

int main()
{
    stack<int> stack;
    stack.push(-10);
    stack.push(20);
    stack.push(70);
    stack.push(40);
    stack.push(50);

    sortStack(stack);

    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }

}