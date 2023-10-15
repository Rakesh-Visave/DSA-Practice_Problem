#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> arr;
void inorder(Node *node)
{
    if (!node)
        return;
    inorder(node->left);
    arr.push_back(node->data);
    inorder(node->right);
}

Node *createBST(int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    Node *root = new Node(arr[mid]);

    root->left = createBST(low, mid - 1);
    root->right = createBST(mid + 1, high);

    return root;
}

Node *buildBalancedTree(Node *root)
{
    inorder(root);
    return createBST(0, arr.size() - 1);
}

int main()
{
    // Hardcoded input array (must be sorted for BST construction)
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *root = buildBalancedTree(new Node(0));

    // Print inorder traversal of the balanced tree
    inorder(root);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
