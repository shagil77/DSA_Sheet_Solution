#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* rightMostNode(TreeNode* root) {
        if(root->right==NULL) return root;

        return rightMostNode(root->right);
    }
    TreeNode* solve(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;

        TreeNode* left = solve(root->left);
        TreeNode* right = solve(root->right);

        if(left!=NULL) {
            TreeNode* rmLeft = rightMostNode(left);

            rmLeft->right = right;
            root->right = left;
            root->left = NULL;
        }
        
        return root;
    }
public:
    void flatten(TreeNode* root) {
        root = solve(root);
    }
};

int main()
{


    return 0;
}