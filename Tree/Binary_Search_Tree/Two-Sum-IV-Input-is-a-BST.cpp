//LEETCODE --  653. Two Sum IV - Input is a BST


#include<iostream>
#include<vector>
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
public:

void storeInorder(TreeNode* root , vector<int> &in)
{
    if(root == NULL)
        return;
    
    storeInorder(root->left , in);
    in.push_back(root->val);
    storeInorder(root->right , in);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        storeInorder(root, inOrder);

        int i = 0;
        int j = inOrder.size()-1;

        int sum = 0;
        while(i < j)
        {
            sum = inOrder[i] + inOrder[j];  
            if(sum == k)
                return true;
            
            else if(sum > k)
                j--;
            else
                i++;
        }
        return false;

        
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int target = 9;

    Solution solution;
    bool found = solution.findTarget(root, target);

    if (found)
        cout << "Target " << target << " found in the binary tree." << endl;
    else
        cout << "Target " << target << " not found in the binary tree." << endl;

    // Clean up memory
    // ...
    
    return 0;
}
