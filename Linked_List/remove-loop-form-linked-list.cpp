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

Node* floydAlgorithm(Node* head) {
    if (head == NULL)
        return NULL;

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && slow != NULL) {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow)
            return slow;
    }

    return NULL;
}

Node* getstatringNodeLoop(Node * head)
{
    if(head == NULL)
        return NULL;

    // step-1 use FCD algorithm and find intersection where S== F 
    Node* intersection = floydAlgorithm(head);
    
    // step-2  set slow at starting position
    Node* slow = head;

    // step-3   run slow and intersection/fast at same speed where slow == intersection return that node becuase it is a  node of statring Loop
    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
     
}

void removeLoop(Node* head)
{
    if(head == NULL)
        return ;

    Node* startingNode = getstatringNodeLoop(head);
    Node* temp = startingNode;

    while(temp->next != startingNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    fifth->next = third;

    Node* current = head;

    Node* ans = getstatringNodeLoop(head);
    cout<<"The Loop starts from Value: "<<ans->data<<endl;

    

   removeLoop(head);

    
    cout << "after Removing Loop from Linked List: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;

}