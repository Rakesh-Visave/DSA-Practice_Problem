
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


    Node* pairWiseSwap(struct Node* head) 
    {
         if(!head->next)
            return head;

        struct Node* itr = head;
        head = head->next;
        itr->next = head->next;
        head->next = itr;
        while(itr){
            struct Node* curr = itr->next;
            if(curr && curr->next){
                itr->next = curr->next;
                curr->next = itr->next->next;
                itr->next->next = curr;
            }else
                break;
            itr = itr->next->next;
        }
        return head;
    }



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    head = pairWiseSwap(head);

    cout << "List after pairwise swap: ";
    printList(head);

    return 0; 
}
