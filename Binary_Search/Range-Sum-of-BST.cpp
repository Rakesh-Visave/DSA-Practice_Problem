// LEETCODE -- 938.Range Sum of BST
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
 

    int rangeSumBST(TreeNode* root, int low, int high) {
         if(!root)
            return 0;
        
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        return rangeSumBST(root->left, low, high);
    }

int main() {
    // Creating a BST manually
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;

    int result = rangeSumBST(root, low, high);
    cout<< "Range sum between " << low << " and " << high << " is: " << result << endl;
}
