// CODESTUDIO -- GFG -- Largest BST

#include<iostream>
#include <limits.h>
using namespace std;


    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


// create a info which reqiure for each node
class  info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root , int &ans)
{
    // base case
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};
    
    // recursive calls
    info left = solve(root->left,ans);
    info right = solve(root->right , ans);

    // get all parameter for curr node
    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data , right.maxi);
    currNode.mini = min(root->data,left.mini);

    // check BST or not
    if(left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini) )
       currNode.isBST = true;
    else
        currNode.isBST = false;


    // find maximum size 
    if(currNode.isBST)
        ans = max(ans,currNode.size);
    
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;

}

int main() {
    // Create a sample binary tree
    TreeNode<int>* root = new TreeNode<int>(50);
    root->left = new TreeNode<int>(30);
    root->right = new TreeNode<int>(60);
    root->left->left = new TreeNode<int>(5);
    root->left->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(45);
    root->right->right = new TreeNode<int>(70);
    root->right->right->left = new TreeNode<int>(65);
    root->right->right->right = new TreeNode<int>(80);

    int largestBSTSize = largestBST(root);
    cout << "Largest BST size: " << largestBSTSize << endl;

    // Clean up the memory
    delete root;

    return 0;
}
