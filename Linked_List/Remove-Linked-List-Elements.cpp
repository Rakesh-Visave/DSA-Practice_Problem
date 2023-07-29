// LEETCODE -- 203.Remove Linked List Elements

#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


    ListNode* removeElementsIteratively(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tail = dummy;

        while(tail != NULL && tail->next != NULL)
        {
            if(tail->next->val == val)
            {
                ListNode * temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
            else
                tail = tail->next;
        }  
        return dummy->next; 
    }

      ListNode* removeElementsRecursively(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        
        head->next = removeElementsRecursively(head->next, val);
        return head->val == val?head->next:head;
    }


// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int valToRemove = 6;

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Call the removeElementIteratively function to remove nodes with value equal to valToRemove Iteratively
    // ListNode* newHead = removeElementsIteratively(head, valToRemove);

    // Call the removeElementsRecursively function to remove nodes with value equal to valToRemove Recursively
    ListNode* newHead = removeElementsRecursively(head, valToRemove);

    std::cout << "Linked List after removing " << valToRemove << ": ";
    printLinkedList(newHead);

    // Clean up the memory (free the allocated nodes)
    ListNode* current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}