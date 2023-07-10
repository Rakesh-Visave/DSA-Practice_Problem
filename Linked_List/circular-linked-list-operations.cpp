#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        int data = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"The Node is Removes and their data is: "<<data<<endl;
    }
    
};

void insertNode(Node* &tail ,int element, int d)
{
    // if list is empty
    if(tail == NULL)
    {
        Node* first = new Node(d);
        tail = first;
        first->next = first;
    }
    else
    {
        // non empty list
        Node* curr = tail;
        while(curr->data != element)
        {
            curr= curr->next;
        }
        // here element if fount insert your node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
        tail = temp;
    }
   
}
void print(Node* tail)
{
    if (tail == NULL)
    {
        cout << "The List is empty...!!!" << endl;
        return;
    }

    Node* temp = tail->next; // Start from the next node of tail

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Stop when we reach the starting point (tail->next)

    cout << endl;
}


void deleteNode(Node* &tail , int value)
{
    // list is empty
    if(tail == NULL)
    {
        cout<<"The List is empty...!!!";
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr)
        {
                tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}



int main()
{
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    deleteNode(tail,9);
    print(tail);

    return 0;
}
