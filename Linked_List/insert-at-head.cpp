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
        this->next = NULL;
    }

    
};

void insertAtHead(Node* &head , int d)
{
    // for inserting first creat a node
    Node* temp = new Node(d);

    // here head means node1
    temp->next = head;

    // assing temp address to head
    head = temp;
}

void print(Node* &head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

int main()
{
    
    // create a new node having data 10
    Node* node1 = new Node(10);
    // cout<<node1->data;

        // point head to node1 and print single node
    Node* head = node1;
    print(head);

    // insert 20 at begining
    insertAtHead(head, 20);
    print(head);

    // insert 30 at beggining
    insertAtHead(head, 30);
    print(head);



    return 0;


}