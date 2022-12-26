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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool leftToRight = true;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(!leftToRight) reverse(level.begin(), level.end());

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};

int main()
{


    return 0;
}