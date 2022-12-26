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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        queue<TreeNode*> q;
        if(root==NULL) return rightSide;
        
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=1; i<=size; i++) {
                TreeNode* curr = q.front();
                if(i==size) {
                    rightSide.push_back(curr->val);
                }
                
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                q.pop();
            }
        }

        return rightSide;
    }
};

int main()
{


    return 0;
}