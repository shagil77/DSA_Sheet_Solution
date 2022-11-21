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
    int solve(TreeNode* root, int &res) {
        if(root==NULL) return 0;
        
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        int temp = max(left, right) + 1;      // To calculate the length of the longest path through the node
        int ans = max(temp, left + right + 1);// To store either the diameter through the current node as root node, or max path 
        res = max(res, ans);                  // Storing the max diameter till the current node
        
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        
        return res-1;
    }
};

int main()
{


    return 0;
}