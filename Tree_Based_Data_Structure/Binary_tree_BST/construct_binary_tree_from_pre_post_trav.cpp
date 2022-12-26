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
    int preIdx, postIdx, N;

    TreeNode* solve(vector<int>& preorder, vector<int>& postorder) {
        if(preIdx == N || postIdx == N) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        if(root->val != postorder[postIdx]) root->left = solve(preorder, postorder);
        if(root->val != postorder[postIdx]) root->right = solve(preorder, postorder);

        postIdx++;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        preIdx = 0; 
        postIdx = 0;
        N = preorder.size();

        return solve(preorder, postorder);
    }
};

int main()
{


    return 0;
}