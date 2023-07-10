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


    bool isPalindrome(vector<int> arr)
    {
        int s = 0;
        int e =arr.size()-1;
        
        while(s <= e)
        {
            if(arr[s] != arr[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node* temp = head;
        
        while(temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return isPalindrome(arr);
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
