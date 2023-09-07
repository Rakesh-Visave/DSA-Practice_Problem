// LEETCODE --92.Reverse Linked List II
#include<iostream>
using namespace std;


    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            
            ListNode* prev = dummy;
            
            for(int i = 1; i<left; i++) {
                prev = prev->next;
            }
            
            ListNode* curr = prev->next;
            
            for(int i = 1; i<=right-left; i++) {
                
                ListNode* temp = prev->next; //0
                prev->next = curr->next; //1
                curr->next = curr->next->next; //2
                prev->next->next = temp; //3
                
            }
        
            return dummy->next;
        }

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = nullptr;

    // Printing the original linked list
    std::cout << "Original Linked List: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Reverse the list from position 2 to 4
    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    // Printing the reversed linked list
    std::cout << "Reversed Linked List from " << left << " to " << right << ": ";
    temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}