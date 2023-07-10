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
    ~Node()
    {
        // get data of deleted value
        int data = this->data;

        // free up the space delete node from memory
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"The Memory is Free with data: "<<data<<endl;
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

void insertAtTail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head , Node* &tail, int position ,int d)
{
    Node* temp = head;

    // for insert at starting
    if(position == 1)
    {
        insertAtHead(head,d);
        return;
    }

    // for going position place to insert element 
    int cnt = 1;
    while(cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // for inserting element at end
    if(temp == tail)
    {
        insertAtTail(tail,d);
        return;
    }
    // suppose postion is 3 so our temp will be at 2 nd postion and next insert given element

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head)
{
    // for deleting first element
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;

        // free up memory
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        // deleting last or middle element
        int cnt = 1;
        Node* curr = head;
        Node* prev = NULL;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}



void print(Node* &head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{

    Node* node1 = new Node(20);
    // cout<<node1->data;

    Node* tail = node1;
    Node* head = node1;

    insertAtHead(head,10);
    // print(head);

    insertAtTail(tail,30); 
    // print(head);
    
    insertAtTail(tail,50); 
    // print(head);

    insertAtPosition(head,tail,4,40);
    // print(head);

    deleteNode(1,head);
    print(head);

    cout<<endl<<"Head is: "<<head->data<<endl; 
    cout<<"tail is: "<<tail->data;

}