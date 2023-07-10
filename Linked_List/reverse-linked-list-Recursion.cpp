// LEETCODE -- 206. Reverse Linked List-Recursion

#include<iostream>
using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

ListNode* reverse(ListNode* head)
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

ListNode* reverseList(ListNode* head) {
    return reverse(head);
        
}


int main()
{
    // Create a linked list with some nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
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

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    current = reversedHead;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory (delete all nodes)
    current = reversedHead;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
