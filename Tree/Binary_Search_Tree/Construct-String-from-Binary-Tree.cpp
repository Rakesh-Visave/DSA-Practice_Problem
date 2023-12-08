#include <iostream>
#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct string from binary tree
std::string tree2str(TreeNode* root) {
    if (!root) {
        return "";
    }
    
    std::string result = std::to_string(root->val);
    std::string l = tree2str(root->left);
    std::string r = tree2str(root->right);
   
    if (!root->left && !root->right) {
        return result;
    }
    
    if (!root->right)
        return result + "(" + l + ")";
    
    if (!root->left)
        return result + "()" + "(" + r + ")";
    
    return result + "(" + l + ")" + "(" + r + ")";   
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    // Display the constructed string from the binary tree
    std::string treeString = tree2str(root);
    std::cout << "Constructed string from binary tree: " << treeString << std::endl;
    
    // Clean up memory (optional)
    delete root;
}