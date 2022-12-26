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
    int count = 0;
    void solve(TreeNode* root, int targetSum) {
        if(root==NULL) return;

        countPaths(root, 0, targetSum);

        solve(root->left, targetSum);
        solve(root->right, targetSum);
    }
    void countPaths(TreeNode* root, long long int sum, int targetSum) {
        if(root==NULL) return;
        sum += root->val;
        if(sum==targetSum) count++;

        countPaths(root->left, sum, targetSum);
        countPaths(root->right, sum, targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);

        return count;
    }
};

int main()
{


    return 0;
}