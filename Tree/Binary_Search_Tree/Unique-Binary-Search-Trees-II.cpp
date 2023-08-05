#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> solve(int left, int right) {
    if (left > right || left < 1) {
        vector<TreeNode*> ans;
        ans.push_back(nullptr);
        return ans;
    }
    if (left == right) {
        vector<TreeNode*> ans;
        TreeNode* temp = new TreeNode;
        temp->val = left;
        temp->left = nullptr;
        temp->right = nullptr;
        ans.push_back(temp);
        return ans;
    }
    vector<TreeNode*> ans;
    for (int i = left; i <= right; i++) {
        vector<TreeNode*> lt = solve(left, i - 1);
        vector<TreeNode*> rt = solve(i + 1, right);
        for (int k = 0; k < lt.size(); k++) {
            for (int j = 0; j < rt.size(); j++) {
                TreeNode* temp = new TreeNode;
                temp->val = i;
                temp->left = lt[k];
                temp->right = rt[j];
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    return solve(1, n);
}

int main() {
    int n = 3; // Change the value of n to test with different inputs

    vector<TreeNode*> result = generateTrees(n);

    // Displaying the generated trees
    for (int i = 0; i < result.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        // Helper function to display the tree in preorder traversal
        function<void(TreeNode*)> preorder = [&](TreeNode* root) {
            if (root == nullptr) return;
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        };
        preorder(result[i]);
        cout << endl;
    }

    // Don't forget to free the allocated memory
    for (int i = 0; i < result.size(); i++) {
        function<void(TreeNode*)> deleteTree = [&](TreeNode* root) {
            if (root == nullptr) return;
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        };
        deleteTree(result[i]);
    }

    return 0;
}
