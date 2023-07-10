#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};
  
node* merge(node* left ,node* right)
{
    
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    
    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right!= NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

    }
    if(left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;   
    }
    if(right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;    

}

node* getMid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

node* mergeSort(node *head) {
    
    // base case of recursive call
    if(head == NULL || head->next == NULL)
        return head;

    // step-1 find mid elemenet by getmid()
    node* mid = getMid(head);

    // step-2 divide a LL in two part where left is head to mid and right is mid->next to NULL
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // step-3recursive call for sorting linked list
    left = mergeSort(left);
    right = mergeSort(right);

    // ste-4 merge two sorted LL into result
    node* result = merge(left, right);

    return result;
}

int main() {
    // Create a hardcoded linked list
    node* head = new node(6);
    node* second = new node(2);
    node* third = new node(8);
    node* fourth = new node(1);
    node* fifth = new node(5);

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Print the original list
    cout << "Original list: ";
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Perform merge sort
    head = mergeSort(head);

    // Print the sorted list
    cout << "Sorted list: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}








