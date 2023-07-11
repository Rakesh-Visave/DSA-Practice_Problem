// LEETCODE -- GFG -- 543. Diameter of Binary Tree

// optimize Approach-2  -- O(n)
// by using pair we can optimized the solution i creat a diameter fast function where through pair i return diamter as well as height at same timee

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

pair<int, int> diameterFast(Node* root)
    {
        if(root == NULL)
        {
            pair<int ,int >p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second +right.second  + 1;

        pair<int, int >ans;

        // finding a diameter
        ans.first = max(op1 , max(op2,op3));

        // finding the height
        ans.second = max(left.second , right.second) +1;

        return ans;
    }

        

    // Function to return the diameter of a Binary Tree.
    int diameterOfBinaryTree(Node* root) {
        return diameterFast(root).first;
        
    }


int main() {
    // Creating the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);  
    root->left->left = newNode(4);
   

   

    // Calculate the diameter of the tree
    int treeDiameter =diameterOfBinaryTree(root);

    // Output the result
    cout << "The diameter of the binary tree is: " << treeDiameter << endl;

    return 0;
}
