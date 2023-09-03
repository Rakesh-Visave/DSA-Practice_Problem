// GFG -- Check if Tree is Isomorphic

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
            return false;
        
        if(root1->data != root2->data)
            return false;
        
        bool a = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right,root2->right);
        bool b = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right ,root2->left);
        return a || b;
    }

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(4);

    if (isIsomorphic(root1, root2))
        cout << " Tree is Isomorphic" << endl;
    else
        cout << "Tree is Not Isomorphic" << endl;

    return 0;
}
