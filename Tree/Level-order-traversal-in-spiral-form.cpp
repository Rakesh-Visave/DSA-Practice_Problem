// GFG -- Level order traversal in spiral form

#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root)
{
    vector<int> result;
    if(root == NULL)
        return result;
    
    queue<Node*> q;
    q.push(root);
    
    bool RightToLeft = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for(int i = 0; i<size; i++)
        {
            Node* temp = q.front();
            q.pop();
            
            int index = RightToLeft ? size-i-1 : i;
            ans[index] = temp->data;
        
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
              q.push(temp->right);
        }
        RightToLeft = !RightToLeft;
        
        for(auto i : ans)
            result.push_back(i);
    }
    return result;
    
}

int main()
{
    // Test case 1
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(7);
    root1->left->right = newNode(6);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    cout << "Spiral Traversal 1: ";
    vector<int> result1 = findSpiral(root1);
    for (int val : result1)
        cout << val << " ";
    cout << endl;

    return 0;
}
