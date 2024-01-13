// LEETCODE -- 2385.Amount of Time for Binary Tree to Be Infected
 
#include<iostream>
#include<climits>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

        int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
          solve(root, start);

        return result;
        
    }


int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(5);

    
    int start = 2;

    int time = amountOfTime(root, start);

    
    cout << "Amount of time for the binary tree to be infected starting from node " << start << " is: " << time << endl;

    // Freeing allocated memory (not necessary in LeetCode environment)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}