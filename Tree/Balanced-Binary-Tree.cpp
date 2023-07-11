// LEETCODE -- GFG -- 110. Balanced Binary Tree

// Approach -1 O(n^2)
// call height function recursively in isBalanced function

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
 
class Solution {
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right) + 1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right) ) <= 1;

        if(left && right && diff)
            return true;
        else
            return false;
        
    }
};

int main() {
    // Create the tree [3, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    bool isTreeBalanced = solution.isBalanced(root);
    cout << "Is the tree balanced? " << (isTreeBalanced ? "true" : "false") << endl;

    // Clean up the allocated memory (optional)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
