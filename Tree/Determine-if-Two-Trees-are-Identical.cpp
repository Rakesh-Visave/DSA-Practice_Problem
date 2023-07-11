// GFG -- Determine if Two Trees are Identical
// LEETCODE -- 100. Same Tree

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


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p != NULL && q == NULL)
            return false;
        if(p == NULL && q != NULL)
            return false;
        
        bool left = isSameTree(p->left , q->left);
        bool right = isSameTree(q->right, q->right);
        bool value = p->val == q->val;

        if(left && right && value)
            return true;
        else
            return false;
    }


int main() {
    // Create the first tree [1, 2, 3]
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create the second tree [1, 2, 3]
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

  
    bool areTreesSame = isSameTree(p, q);
    cout << "Are the trees same? " << (areTreesSame ? "true" : "false") << endl;

    // Clean up the allocated memory (optional)
    delete p->right;
    delete p->left;
    delete p;
    delete q->right;
    delete q->left;
    delete q;

    return 0;
}
