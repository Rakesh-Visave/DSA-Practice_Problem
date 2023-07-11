
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
    
Node* solve(int in[], int post[], int& index, int n, int inOrderStart, int inOrderEnd)
{
    if (index < 0)
        return NULL;
    if (inOrderStart > inOrderEnd)
        return NULL;

    int element = post[index--];
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


    root->right = solve(in, post, index, n, position + 1, inOrderEnd);
    root->left = solve(in, post, index, n, inOrderStart, position - 1);

    return root;
}
Node *buildTree(int in[], int post[], int n) {
   int postOrderIndex = n-1;
        Node* ans = solve(in,post,postOrderIndex,n,0,n-1);
        return ans;
}
    
void preTraversal(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preTraversal(root->left);
    preTraversal(root->right);
}

int main()
{
    int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* result = buildTree(inorder, postorder, n);

    // Printing the constructed binary tree using inorder traversal
    cout << "Post order traversal of the constructed binary tree: "<<endl;
    preTraversal(result);
    cout << endl;

    return 0;
}

