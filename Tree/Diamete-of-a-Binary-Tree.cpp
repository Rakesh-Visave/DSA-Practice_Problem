// LEETCODE -- GFG -- 543. Diameter of Binary Tree

// Approach-1 where T.C -- O(n^2)  
// called height function recursively in diameter funtion

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

        int height(Node* root)
        {
            if(root == NULL)
                return 0;
                
            int left = height(root->left);
            int right = height(root->right);
            
            int ans = left + right + 1;
            return ans;
        }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
            
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        
        int opt3 = height(root->left) + height(root->right) + 1;
        
        int ans = max(opt1 , max(opt2,opt3));
        return ans;
    }


int main() {
    // Creating the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);  
    root->left->left = newNode(4);
   

   

    // Calculate the diameter of the tree
    int treeDiameter =diameter(root);

    // Output the result
    cout << "The diameter of the binary tree is: " << treeDiameter << endl;

    return 0;
}
