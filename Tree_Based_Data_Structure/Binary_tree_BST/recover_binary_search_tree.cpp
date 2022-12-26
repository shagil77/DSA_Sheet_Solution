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
    set<int> outOfOrderNodes;
    void solve(TreeNode* root, long long int mn, long long int mx) {
        if(root==NULL) return;
        int val = root->val;
        if(val<=mn) {
            outOfOrderNodes.insert(val);
            outOfOrderNodes.insert(mn);

            solve(root->left, mn, mx);
            solve(root->right, mn, mx);
        }
        else if(val>=mx){
            outOfOrderNodes.insert(val);
            outOfOrderNodes.insert(mx);

            solve(root->left, mn, mx);
            solve(root->right, mn, mx);
        } else {
            solve(root->left, mn, val);
            solve(root->right, val, mx);
        }   
    }
    void replace(TreeNode* root, int a, int b) {
        if(root==NULL) return;
        if(root->val == a) {
            root->val = b;
        } else if(root->val == b) {
            root->val = a;
        }

        replace(root->left, a, b);
        replace(root->right, a, b);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root, LLONG_MIN, LLONG_MAX);

        vector<int> replacements(outOfOrderNodes.begin(), outOfOrderNodes.end());
        int n = replacements.size();

        replace(root, replacements[0], replacements[n-1]);
        // replace(root);
        for(auto it:outOfOrderNodes) cout<<it<<" ";
    }
};

int main()
{


    return 0;
}