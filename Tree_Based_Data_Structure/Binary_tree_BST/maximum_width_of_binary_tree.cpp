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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        int width = 1;

        while(!q.empty()) {
            int size = q.size();
            long long int minIdx=q.front().second;
            long long int left = -1, right = -1;

            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front().first;
                long long int idx = q.front().second - minIdx;
                q.pop();

                if(i==0) left = idx;
                if(i==size-1) right = idx;

                if(curr->left != NULL) q.push({curr->left, 2*idx+1});
                if(curr->right != NULL) q.push({curr->right, 2*idx+2});
            }
            long long int diff = right-left+1;
            width = (diff>width)?diff:width;
        }

        return width;
    }
};

int main()
{


    return 0;
}