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

Node* getMiddle(Node* &head)
{
    if(head == NULL ||head->next == NULL)
    {
        return head;
    }
    if(head->next->next == NULL )
    {
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;

}


Node *findMiddle(Node *head) {
        return getMiddle(head);
}

int main() {
    // Create the linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // Find the middle node
    Node* middle = findMiddle(head);
    
    // Print the middle node's data
    if (middle != NULL) {
        cout << "Middle node data: " << middle->data << endl;
    } else {
        cout << "Linked list is empty." << endl;
    }
    
    // Deallocate memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    
    return 0;
}