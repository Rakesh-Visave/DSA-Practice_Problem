// 4 type of tree traversals 
//  1.level order / BFS
//  2.inorder
//  3.preorder
//  4.postorder

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

void preorder(node* root)
{
    if(root == NULL)
        return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root == NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root == NULL)
        return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



int main()
{
    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout<<"Level order Traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"The Preorder Travel: "<<endl;
    preorder(root);

    cout<<"The postorder Travel: "<<endl;
    postorder(root);

    cout<<"The inorder Travel: "<<endl;
    inorder(root);


}