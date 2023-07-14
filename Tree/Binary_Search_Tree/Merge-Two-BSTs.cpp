#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

    template <typename T>
    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };


void storeInorder(TreeNode<int>* root , vector<int > &in)
{
    if(root == NULL)
        return;
    
    storeInorder(root->left,in );
    in.push_back(root->data);
    storeInorder(root->right,in);
}
vector<int> merge(vector<int> &a , vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
  
    int i = 0, k = 0, j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            ans[k] = a[i];
            i++;
            k++;
        }
        else
        {
            ans[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < a.size())
    {
        ans[k] = a[i];
        k++;
        i++; 
    }
    while(j < b.size())
    {
        ans[k] = b[j];
        k++;
        j++; 
    }
    return ans;
}

TreeNode<int>* inorderBST(int s, int e ,vector<int> ans)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(ans[mid]);
    root->left = inorderBST(s,mid-1,ans);
    root->right = inorderBST(mid+1, e, ans);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // step-1 store inorder in Vector<int>
    vector<int> bst1, bst2;
    storeInorder(root1,bst1);
    storeInorder(root2 , bst2);

    // step-2 merge two sorted Arrat

    vector<int> mergedArray = merge(bst1,bst2); 

    int s = 0;
    int e = mergedArray.size()-1;

    return inorderBST(s,e,mergedArray);

}

void inorder(TreeNode<int>* root)
{
    if(root == NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    // Create two sample BSTs
    TreeNode<int>* root1 = new TreeNode<int>(2);
    root1->left = new TreeNode<int>(1);
    root1->right = new TreeNode<int>(3);

    TreeNode<int>* root2 = new TreeNode<int>(5);
    root2->left = new TreeNode<int>(4);
    root2->right = new TreeNode<int>(6);

    // Merge the two BSTs
    TreeNode<int>* mergedRoot = mergeBST(root1, root2);

    cout<<"The merged Array is: ";
    inorder(mergedRoot);


}