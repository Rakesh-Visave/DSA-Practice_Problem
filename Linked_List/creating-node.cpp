#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
};

int main()
{
    node* node1 = new node(100);
    cout<<"Node data is: "<<node1->data <<endl;
    cout<<"Node next pointer is: "<<node1->next;
}