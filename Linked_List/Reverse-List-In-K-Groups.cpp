// CODESTUDIO -- ReverseList In K Groups

#include<iostream>
using namespace std;

class Node {
  public:
     int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
  };


Node* kReverse(Node* head, int k) {
    if(head == NULL)
        return NULL;
    
    // step1- reverse first K element
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;  
    }
    // step2- recursion call
    if(next != NULL)
    {
        head->next = kReverse(next,k);

    }
    return prev;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
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
    fifth->next = sixth;

    // Reverse the linked list in groups of size 3
    int k = 2;
    head = kReverse(head, k);

    // Print the reversed linked list
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory
    current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
