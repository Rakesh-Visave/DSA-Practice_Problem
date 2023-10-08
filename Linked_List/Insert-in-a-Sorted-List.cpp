

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}



    Node *sortedInsert(struct Node* head, int data) {
        struct Node * newNode =  new Node(data);
        if(head->data >= data){
            newNode->next = head;
            return newNode;
        }
        struct Node * itr = head;
        while(itr->next && itr->next->data < data){
            itr = itr->next;
        }
        newNode->next = itr->next;
        itr->next = newNode;
        return head;
    }

int main() {
    // Creating a sorted linked list: 1 -> 3 -> 5 -> 7 -> 9
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);

    cout << "Original linked list: ";
    printList(head);

    // Inserting a new node with data 4
    head = sortedInsert(head, 4);
    cout << "Linked list after inserting 4: ";
    printList(head);

    // Inserting a new node with data 0
    head = sortedInsert(head, 0);
    cout << "Linked list after inserting 0: ";
    printList(head);

    // Inserting a new node with data 10
    head = sortedInsert(head, 10);
    cout << "Linked list after inserting 10: ";
    printList(head);

    // Inserting a new node with data 6
    head = sortedInsert(head, 6);
    cout << "Linked list after inserting 6: ";
    printList(head);

    return 0;
}
