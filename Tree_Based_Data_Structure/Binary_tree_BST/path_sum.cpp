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
    int sum, target;
    bool solve(TreeNode* root) {
        if(root == NULL) return false;
        
        sum += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum == target) return true;
            sum -= root->val;
            return false;
        }
        
        if(solve(root->left)) return true;
        if(solve(root->right)) return true;
        sum -= root->val;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        sum = 0;
        target = targetSum;
        
        return solve(root);
    }
};

int main()
{


    return 0;
}