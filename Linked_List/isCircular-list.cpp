#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next  = NULL;
    }
};

bool isCircular(Node* head)
{
    if(head == NULL)
        return true;
    
    Node* temp = head->next;
    while(temp!= NULL && temp != head)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return false;
    }
    if(temp == head)
    {
        return true;
    }
}

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    
    // connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    bool ans = isCircular(head);
    if(ans)
        cout<<"The Linked List is Circular";
    else    
        cout<<"The Linked List is Not Circular";
    
    return 0;

}