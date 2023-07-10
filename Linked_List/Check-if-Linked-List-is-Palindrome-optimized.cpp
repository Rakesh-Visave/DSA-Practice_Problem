// Check if Linked List is Palindrome-optimized  S.C - O(1)

// LEETCODE -- Check if Linked List is Palindrome


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include<vector>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* getMid(Node* head)
{
    Node* fast = head->next;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

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
    
    
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL)
            return true;
    

    //  step-1 Find mid element
        Node* middle = getMid(head);

    //  step-2  reverse LL element from mid->next to end/NULL
        Node* temp = middle->next;
        middle->next = reverse(temp);

    // step-3 = compare both Halfs
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    } 
    // step-4 repated 2nd step 
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}


int main() {
  // Create a linked list
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(2);
  head->next->next->next->next = new Node(1);



  // Check if the linked list is a palindrome
  bool isPalin = isPalindrome(head);

  if (isPalin) {
    cout << "Linked list is a palindrome." << endl;
  } else {
    cout << "Linked list is not a palindrome." << endl;
  }

  return 0;
}
