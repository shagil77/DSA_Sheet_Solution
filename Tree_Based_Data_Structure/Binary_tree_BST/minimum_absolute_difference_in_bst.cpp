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
    int rightMostElement(TreeNode* node) {
        TreeNode* p = node;
        while(p->right != NULL) {
            p = p->right;
        }
        
        return p->val;
    }
    int leftMostElement(TreeNode* node) {
        TreeNode* p = node;
        while(p->left != NULL) {
            p = p->left;
        }
        
        return p->val;
    }
    int solve(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return INT_MAX;
        
        int right, left, diff = INT_MAX;
        if(root->left != NULL) {
            right = rightMostElement(root->left);
            diff = min(diff, root->val - right);
        }
        if(root->right != NULL) {
            left = leftMostElement(root->right);
            diff = min(diff, left - root->val);
        }
        
        return min(diff, min(solve(root->left), solve(root->right)));
    }
public:
    int getMinimumDifference(TreeNode* root) {
        return solve(root);
    }
};

int main()
{


    return 0;
}