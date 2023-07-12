#include<iostream>
#include<queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node( int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* root , int data)
{
    if(root == NULL)
    {
        root = new Node(data);
            return root;
    }
    if(data > root->data)
        root->right = insertToBST(root->right, data);
    else
        root->left = insertToBST(root->left, data);
    
    return root;
}

Node* minElement(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteInBST(Node* root , int val)
{
    if(root == NULL)
        return root;

    if(root->data == val)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
            // left child
            if(root->left != NULL && root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // right child
            if(root->left == NULL && root->right != NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
        
        // 2 child
        if(root->left != NULL && root->right != NULL)
        {
            int min = minElement(root->right)->data;
            root->data = min;
            root->right = deleteInBST(root->right , min);
            return root;
        }

    }
    if(root->data > val)
        root->left = deleteInBST(root->left, val);
    else    
        root->right = deleteInBST(root->right, val);

    
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertToBST(root, data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
 
    while(!q.empty())
    {
        Node* temp = q.front();
        
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


int main()
{
    Node * root = NULL;
    cout<<"Enter the data for creating BST: ";
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);
    cout<<"BST before Deletion:"<<endl;
    levelOrderTraversal(root);
    
     cout<<"BST After Deletion:"<<endl;
     deleteInBST(root,8);
    levelOrderTraversal(root);
    return 0;
}