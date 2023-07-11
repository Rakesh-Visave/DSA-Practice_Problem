
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	    
    	queue<Node*> q;
    	q.push(root);
    	
    	// insert element in ZigZag manner
        bool leftToRight = true;
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> ans(size);
    	    for(int i = 0; i < size; i++)
    	    {
    	        Node* temp = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight ? i : size-i-1;
    	        ans[index] = temp->data;
    	        
    	        if(temp->left)
    	            q.push(temp->left);
    	           
    	       if(temp->right)
    	            q.push(temp->right);
    	    }
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i : ans)
    	        result.push_back(i);
    	}
    	return result;
    	
    }


int main() {
    // Create the tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Perform zig-zag traversal
    vector<int> result = zigZagTraversal(root);

    // Print the result
    cout << "Zig-Zag Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
