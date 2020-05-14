#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(NULL), left(NULL), right(NULL)  {}
};

TreeNode* createBST(vector<int> vec, TreeNode* root, int i, int n){
    if (i < n)
    {   TreeNode* temp = new TreeNode;
        if (vec[i] == 0){
            root = NULL;
            return root;
            
        } else{
            temp -> val = vec[i];
            temp -> left = NULL;
            temp -> right = NULL;
        }
        root = temp;
        root->left = createBST(vec,root->left, 2*i+1, n);
        root->right = createBST(vec,root->right, 2*i+2, n);
    }
    return root;
}

bool IsSubtreeLesser (TreeNode*, int);
bool IsSubtreeGreater (TreeNode*, int);

bool isBST(TreeNode* root){
    if(root==NULL) return true;
    if(IsSubtreeLesser (root->left,root->val)&& IsSubtreeGreater(root->right,root->val) && isBST(root->left) && isBST(root->right)) return true;
    return false;
}

bool IsSubtreeLesser (TreeNode* root, int value){
    if (root==NULL) return true;
    if (root->val<=value && IsSubtreeLesser (root->left,value) && IsSubtreeLesser (root->right,value)) return true;
    return false;
}

bool IsSubtreeGreater (TreeNode* root, int value){
    if (root==NULL) return true;
    if (root->val>value && IsSubtreeGreater (root->left,value) && IsSubtreeGreater (root->right,value)) return true;
    return false;
}

void SolveD() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);}
    TreeNode* root = createBST(a,root,0,n);
    if (isBST(root)){
        cout<<"true";
    }
    else
        cout<<"false";
    return;
}

int main() {
    SolveD();
    return 0;
}
