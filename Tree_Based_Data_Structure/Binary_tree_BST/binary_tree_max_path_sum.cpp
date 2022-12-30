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
    void pathSum(TreeNode* root, int sum, int &mxSum) {
        if(root==NULL) return;
        sum+=root->val;
        mxSum = max(sum, mxSum);

        pathSum(root->left, sum, mxSum);
        pathSum(root->right, sum, mxSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return INT_MIN;
        if(root->left==NULL && root->right==NULL) return root->val;

        int mxSum = INT_MIN, leftSum = INT_MIN, rightSum = INT_MIN;
        pathSum(root->left, 0, leftSum);
        pathSum(root->right, 0, rightSum);

        mxSum = max(mxSum, root->val);
        mxSum = max(mxSum, max(leftSum, rightSum));
        if(leftSum!=INT_MIN && rightSum!=INT_MIN) {
            mxSum = max(mxSum, root->val+leftSum+rightSum);
            mxSum = max(mxSum, root->val+max(leftSum, rightSum));
        }
        if(leftSum!=INT_MIN && rightSum==INT_MIN) mxSum = max(mxSum, root->val+leftSum);
        if(rightSum!=INT_MIN && leftSum==INT_MIN) mxSum = max(mxSum, root->val+rightSum);
        
        mxSum = max(mxSum, max(maxPathSum(root->left), maxPathSum(root->right)));

        return mxSum;
    }
};

int main()
{


    return 0;
}