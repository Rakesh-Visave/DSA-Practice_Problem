#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
 
    while(!q.empty())
    {
        node* temp = q.front();
        
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);       
        }
    }
}

node* buildTree(node* root)
{
    int data;
    cout<<"Enter Element: "<<endl;
    cin>>data;

    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter the Data in left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the Data in right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout<<"Level order Traversal : "<<endl;
    levelOrderTraversal(root);
}