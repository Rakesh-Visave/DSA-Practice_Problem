
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
    }
    
    Node* insertAtTail(struct Node* &head, struct Node* &tail, int data)
    {
        Node* temp = new Node(data);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        return tail;
            
    }
    
    Node* addNode(struct Node* first, struct Node* second)
    {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if(first != NULL)
                val1 = first->data;
                
            int val2 = 0;
            if(second != NULL)
                val2 = second->data;
                
            int sum = val1 + val2 + carry;
            
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail , digit);
            
            carry = sum /10;
            
            if(first!= NULL)
                first = first->next;
                
            if(second != NULL)
                second = second->next;
        }
        return ansHead;
        
        
    }
  
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // step-1  reverse both the list by reverse function
        first = reverse(first);
        second = reverse(second);
        
        // step-2 add 2 Linked list Node
        Node* ans = addNode(first,second);
        
        // step-2 reverse the LL
        ans = reverse(ans);
        
        return ans;
    }

int main()
{
    // Create the first linked list: 2 -> 4 -> 9
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(9);

    // Create the second linked list: 5 -> 6 -> 4 -> 9
    Node* second = new Node(5);
    second->next = new Node(6);
    second->next->next = new Node(4);
    second->next->next->next = new Node(9);

    // Call the addTwoLists function
    Node* res = addTwoLists(first, second);

    // Print the result
    while(res != NULL)
    {
        cout<<" "<<res->data;
        res =res->next;
    }

    return 0;
}


