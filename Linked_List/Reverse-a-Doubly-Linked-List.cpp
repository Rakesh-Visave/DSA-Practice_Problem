// GFG -- Reverse a Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


    Node* reverseDLL(Node * head)
    {
         Node* curr = head;

        while (curr) {
            head = curr;
            Node* prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }

        return head;
    }
int main() {
    // Creating a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original Doubly Linked List: ";
    displayList(head); // Displaying the original list: 1 2 3 4 5
    cout << endl;

    head = reverseDLL(head);

    cout << "Reversed Doubly Linked List: ";
    displayList(head); // Displaying the reversed list: 5 4 3 2 1
    cout << endl;

    return 0;
}
