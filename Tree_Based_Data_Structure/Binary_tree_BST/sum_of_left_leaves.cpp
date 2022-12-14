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
    int solve(TreeNode* root, bool isLeft) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL && isLeft) return root->val;
        
        int sum = 0;
        sum += solve(root->left, true);
        sum += solve(root->right, false);
        
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};

int main()
{


    return 0;
}