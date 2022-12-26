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
    int idx;
    int ans;
    void solve(TreeNode* root) {
        if(root==NULL) return;

        solve(root->left);
        idx--;
        if(idx==0) {
            ans=root->val;
            return;
        }
        solve(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        idx = k;
        ans = -1;

        solve(root);

        return ans;
    }
};

int main()
{


    return 0;
}