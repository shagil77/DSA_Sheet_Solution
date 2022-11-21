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
    void solve(TreeNode* root, string currPath, vector<string> &ans) {
        currPath += to_string(root->val) + "->";
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(currPath.substr(0, currPath.length()-2));
            return;
        }
        
        if(root->left != NULL) {
            solve(root->left, currPath, ans);
        } 
        if(root->right != NULL) {
            solve(root->right, currPath, ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        
        return ans;
    }
};

int main()
{


    return 0;
}