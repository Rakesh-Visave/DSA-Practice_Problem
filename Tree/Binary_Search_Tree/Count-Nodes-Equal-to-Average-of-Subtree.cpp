// LEETCODE -- 2265.Count Nodes Equal to Average of Subtree
#include<iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

    int result;
    int sum(TreeNode* root, int &count) {
        if(!root)
            return 0;
        
        count++;
        
        int l = sum(root->left, count);
        int r = sum(root->right, count);
        
        return l + r + root->val;
    }
    
    void solve(TreeNode* root) {
        if(!root)
            return;
        
        int count = 0;
        int totalSum = sum(root, count);
        
        if((totalSum)/count == root->val) {
            result++;
        }
        
        solve(root->left);
        solve(root->right);
        
    }
    int averageOfSubtree(TreeNode* root) {
         result = 0;
        
        solve(root);
        
        return result;
    }


int main() {
    // Creating the tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    // Calling the function
    int result = averageOfSubtree(root);

    // Printing the result
    cout << "Number of nodes with value equal to average of subtree: " << result << std::endl;

    // Don't forget to free the allocated memory for the tree nodes
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;
    
    return 0;
}
