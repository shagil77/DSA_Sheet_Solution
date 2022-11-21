#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* A) {
    if(A==NULL) return 0;
    
    return (1 + max(height(A->left), height(A->right)));
}
int isBalanced(TreeNode* A) {
    // if(A==NULL) return 1;
    // if(abs(height(A->left)-height(A->right))<=1) {
    //     if(!isBalanced(A->left) || !isBalanced(A->right)) {
    //         return 0;
    //     }
    // }
    // return 1;

    if(A==NULL) return 1;

    int l=height(A->left), r=height(A->right);

    if(abs(l-r)<=1) return (isBalanced(A->left) && isBalanced(A->right));

    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        if(left == INT_MIN) return INT_MIN;
        int right = height(root->right);
        if(right == INT_MIN) return INT_MIN;
        
        if(abs(left-right)>1) return INT_MIN;
        return (max(left, right)+1);
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        if(h == INT_MIN) return false;
        return true;
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->left->left=new TreeNode(5);
    root->right->left=new TreeNode(6);

    cout<<isBalanced(root);

    return 0;
}