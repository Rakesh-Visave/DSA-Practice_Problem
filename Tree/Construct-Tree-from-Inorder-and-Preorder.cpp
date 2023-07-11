
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
    
Node* solve(int in[], int pre[], int& index, int n, int inOrderStart, int inOrderEnd)
{
    if (index >= n)
        return NULL;
    if (inOrderStart > inOrderEnd)
        return NULL;

    int element = pre[index++];
    Node* root = new Node(element);

    int position = -1;
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (in[i] == element)
        {
            position = i;
            break;
        }
    }


    root->left = solve(in, pre, index, n, inOrderStart, position - 1);
    root->right = solve(in, pre, index, n, position + 1, inOrderEnd);

    return root;
}

    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in,pre,preOrderIndex,n,0,n-1);
        return ans;
    }
    
void postTraversal(Node* root)
{
    if (root == NULL)
        return;

    postTraversal(root->left);
    postTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    int inorder[] = {3,1,4,0,5,2};
    int preorder[] = {0,1,3,4,2,5};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* result = buildTree(inorder, preorder, n);

    // Printing the constructed binary tree using inorder traversal
    cout << "Post order traversal of the constructed binary tree: ";
    postTraversal(result);
    cout << endl;

    return 0;
}

