#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;

    }
    ~Node()
    {
        int data = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is Free with Node data:"<<data<<endl;
    }
};

void insertAtHead(Node* &head, int d)
{
    // creating new node for Data d
    Node* temp = new Node(d);

    // insert at head
    temp->next = head;
    head->prev = temp;

    // moving a head in right place
    head = temp;

}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
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
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* &head)
{
    // for deleting first element
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

int nodeLength(Node* &head)
{
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // prints DDL
     print(head);

    insertAtHead(head,5);
    print(head);

    insertAtTail(tail,15);
    print(head);

    // insert at middle
    insertAtPosition(head,tail,2,20);
    print(head);

    // insert at first
    insertAtPosition(head,tail,1,2);
    print(head);

    // insert at last
     insertAtPosition(head,tail,6,25);
    print(head);

    deleteNode(1,head);
    print(head); 

    deleteNode(5,head);
    print(head);    

    cout<<endl<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data;







    // // gives a size of Length
    // int size = nodeLength(head);
    // cout<<endl;
    // cout<<"The size of DDL is: "<<size;
    
    return 0;
}