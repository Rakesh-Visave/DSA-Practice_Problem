#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(Node* root, int key) {
    if (key < root->data) {
        if (root->left != nullptr)
            insert(root->left, key);
        else
            root->left = new Node(key);
    } else if (key > root->data) {
        if (root->right != nullptr)
            insert(root->right, key);
        else
            root->right = new Node(key);
    }
}

void inorder(Node* node, vector<int> &arr, vector<int> &leaf){
    if(!node)
        return;

    inorder(node->left, arr, leaf);
    arr.push_back(node->data);
    if(!node->left && !node->right)
        leaf.push_back(node->data);
    inorder(node->right, arr, leaf);
}

bool isDeadEnd(Node *root)
{
    vector<int> arr, leaf;
    arr = {0};  // Initialize with a 0 value to handle the edge case of root being 1.
    leaf = {};
    inorder(root, arr, leaf);

    int j = 0;
    for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
        if(arr[i] == leaf[j]){
            if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                return true;
            ++j;
        }
    }

    return false;
}

int main() {
    Node *root = new Node(8);
    insert(root, 5);
    insert(root, 11);
    insert(root, 2);
    insert(root, 7);
    insert(root, 9);
    insert(root, 13);
    // Insert more nodes as needed

    if(isDeadEnd(root))
        cout << "BST contains a dead end.";
    else
        cout << "BST does not contain a dead end.";

    return 0;
}
