// LEETCODE -- GFG -- CODESTUDIO -- Reverse the Linked list -Iterative approach

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
        

Node* reverseLinkedList(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;

        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
    return  prev;
    }
}

int main()
{
    // Create a linked list with some nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

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

    // Reverse the linked list
    Node* reversedHead = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    current = reversedHead;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory (delete all nodes)
    current = reversedHead;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

