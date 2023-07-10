#include<iostream>
#include<map>
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
    
};

bool detectCycle(Node* head)
{
    if(head == NULL)
        return false;

    map<Node* ,bool> visited;
    Node* temp = head;

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            cout<<"Cycle is detected at value: "<<temp->data;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;

    }
    return false;

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

    // here i creat a cycle
    fifth->next = second;

    bool ans = detectCycle(head);
    if(ans)
        cout<<endl;
    else    
        cout<<"Cycle is not detected";
    
    return 0;

}