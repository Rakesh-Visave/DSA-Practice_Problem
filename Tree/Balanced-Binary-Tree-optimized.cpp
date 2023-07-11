// LEETCODE -- GFG -- 110. Balanced Binary Tree

// Approach-2 -- O(n)
// here i am using pair<bool,int> for storing height and their balanced condition bool value

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
     pair<bool,int> isBalancedFast(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool leftans = left.first;
        bool rightans = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftans && rightans && diff)
            ans.first = true;
        else
            ans.first = false;

        return ans;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
        
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
