#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


    ListNode* partition(ListNode* head, int x) {
        ListNode* small  = new ListNode(0);
        ListNode* large  = new ListNode(0);
        
        ListNode* smallP = small;
        ListNode* largeP = large;
        
        while(head) {
            if(head->val < x) {
                smallP->next = head;
                smallP = smallP->next;
            } else {
                largeP->next = head;
                largeP = largeP->next;
            }
            
            head = head->next;
        }
        
        largeP->next = NULL;
        smallP->next = large->next;
        return small->next;

    }



int main() {
    // Creating the linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    std::cout << "Original Linked List:" << std::endl;
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    ListNode* newHead = partition(head, x);

    std::cout << "Linked List after partitioning around " << x << ":" << std::endl;
    current = newHead;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}