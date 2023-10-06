// GFG -- Reverse alternate nodes in Link List


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


    void rearrange(struct Node *odd)
    {
         struct Node* even = odd;
        struct Node* revOdd = NULL;
        struct Node* itr = odd;
        while(itr){
            struct Node* nextItr = itr->next;
            if(nextItr){
                even->next = itr->next->next;
                if(even->next)
                even = even->next;
                nextItr->next = revOdd;
                revOdd = nextItr;
            }else
                break;
            itr = even;
        }
        even->next = revOdd;
    }

int main()
{
    // Hardcoded input: 7 nodes with values 1, 2, 3, 4, 5, 6, 7
    start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
    start->next->next->next->next->next = new Node(6);
    start->next->next->next->next->next->next = new Node(7);

    printf("Original list: ");
    printList(start);

    rearrange(start);

    printf("Modified list: ");
    printList(start);

    return 0;
}


