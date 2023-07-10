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

bool floydAlgorithm(Node* head) {
    if (head == NULL)
        return false;

    // step-1 create two pointer fast and slow
    Node* fast = head;
    Node* slow = head;

    // step-2  run fast twice and slow ones and stop when fast reaches at NULL vlaue
    while (fast != NULL && slow != NULL) {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

    // Step-3  if  F==S then cycle is present return true else return false
        if (fast == slow)
            return true;
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

    bool ans = floydAlgorithm(head);
    if(ans)
        cout<<"Cycle is detected";
    else    
        cout<<"Cycle is not detected";
    
    return 0;

}