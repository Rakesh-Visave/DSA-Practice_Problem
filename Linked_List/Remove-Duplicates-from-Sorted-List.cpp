// LEETCODE --- 83.Remove Duplicates from Sorted List

#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode* curr = head;
        while(curr != NULL)
        {
            
            if((curr->next !=NULL) && curr->val == curr->next->val)
            {
                ListNode* next_next = curr->next->next;
                ListNode* next = curr->next;
                delete(next);
                curr->next = next_next;
            }
            else
                curr = curr->next;
        }
        return head;
        
    }

int main()
{
    // Create a linked list with some nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(4);

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Print the original linked list
    cout << "Original Linked List: ";
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    ListNode* Head = deleteDuplicates(head);

    // Print the  linked list after removing Link List
    cout << "Reversed Linked List: ";
    current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory (delete all nodes)
    current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
