#include <bits/stdc++.h>
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

void count_nodes(Node* root,int &c){
    if(!root) return;
    count_nodes(root->left,c);
    c++;
    count_nodes(root->right,c);
}
 
void func(Node* root,Node* &cur,Node* &prev,int &c,int k,int &f){
    if(!root) return;
    func(root->left,cur,prev,c,k,f);
    if(prev==NULL){
        prev = root;
        c++;
    }
    else if(c==k){
        c++;
        cur = root;
        f = 1;
        return;
    }
    else if(f==0){
        c++;
        prev = root;
    }
    func(root->right,cur,prev,c,k,f);
}

float findMedian(struct Node *root)
{
      int n = 0;
      count_nodes(root,n);
      Node* cur = NULL;
      Node* prev = NULL;
      int c = 1;
      int x = (n/2)+1;
      int f = 0;
      func(root,cur,prev,c,x,f);
      if(n&1){
          float ans = (cur->data)*1.0;
          return ans;
      }
      else {
          float ans = ((cur->data+prev->data)*1.0)/(2*1.0);
          return ans;
      }
}


int main() {
    // Create the binary search tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Find the median of the binary search tree
    float median = findMedian(root);

    std::cout << "Median of the binary search tree: " << median << std::endl;

    // Clean up the memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
