// LEETCODE -- 21.Merge Two Sorted Lists

#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }

        }
        if(list1 != NULL)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        if(list2 != NULL)
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    ans= ans->next;
    return ans;
    }

int main() {
    // Create the first sorted list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create the second sorted list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);



    // Merge the two sorted lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    ListNode* temp = mergedList;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}