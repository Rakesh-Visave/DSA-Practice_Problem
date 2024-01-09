// LEETCODE -- 872.Leaf-Similar Trees
#include<iostream>
#include<algorithm>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


       void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;

    }

    int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    // Creating tree 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);
    root2->right->left = new TreeNode(9);
    root2->right->right = new TreeNode(8);
    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);

    bool areSimilar = leafSimilar(root1, root2);

    if (areSimilar) {
        cout << "The leaf sequences of the trees are similar." << endl;
    } else {
        cout << "The leaf sequences of the trees are not similar." << endl;
    }

    return 0;
}
