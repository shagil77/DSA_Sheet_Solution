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
    bool solve(TreeNode* root, long long int mn, long long int mx) {
        if(root == NULL) return true;
        int val = root->val;
        
        if(mn<val && val<mx) {
            if(solve(root->left, mn, val) && solve(root->right, val, mx)) return true;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main()
{


    return 0;
}