// CODESTUDIO -- sort-linked-list of 1s 2s 0s 

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
            zeroCount++;
        else if(temp->data == 1)
            oneCount++;
        else if(temp->data == 2)
            twoCount++;

        temp = temp->next;
    }
    temp = head;

    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;

}

int main()
{
    // Create a linked list with some nodes
    Node* head = new Node(2);
    Node* second = new Node(0);
    Node* third = new Node(0);
    Node* fourth = new Node(1);

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Print the original linked list
    cout << "Original Linked List: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

   
    Node* sortedHead = sortList(head);

    // Print the sorted linked list
    cout << "Reversed Linked List: ";
    current = sortedHead;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory (delete all nodes)
    current = sortedHead;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
