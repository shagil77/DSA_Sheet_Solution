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
    bool solve(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        if(root->val != subRoot->val) return false;
        
        bool left = solve(root->left, subRoot->left);
        bool right = solve(root->right, subRoot->right);
        
        return (left && right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(solve(root, subRoot)) return true;
        
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        
        return (left || right);
    }
};

int main()
{


    return 0;
}