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
    vector<TreeNode*> createBST(int l, int h) {
        if(l>h) {
            vector<TreeNode*> base;
            base.push_back(NULL);
            return base;
        }

        vector<TreeNode*> uniqueBSTs;
        for(int i=l; i<=h; i++) {
            vector<TreeNode*> left = createBST(l,i-1);
            vector<TreeNode*> right = createBST(i+1,h);
            for(TreeNode* leftRoot: left) {
                for(TreeNode* rightRoot: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    uniqueBSTs.push_back(root);
                }
            }
        }

        return uniqueBSTs;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return createBST(1, n);
    }
};

int main()
{


    return 0;
}