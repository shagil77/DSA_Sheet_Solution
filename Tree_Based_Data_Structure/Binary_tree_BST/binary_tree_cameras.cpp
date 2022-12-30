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
    int count;
    // -1 - Camera is necessary for covering the child node
    //  0 - Camera is installed on the child node
    //  1 - Camera is covering the child node
    int solve(TreeNode* root) {
        if(root==NULL) return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if(left==-1 || right==-1) {
            count++;
            return 0;
        }
        if(left==0 || right==0) return 1;
        return -1;

    }
public:
    int minCameraCover(TreeNode* root) {
        count=0;
        int cameraReq = solve(root);
        if(cameraReq==-1) count++;

        return count;
    }
};

int main()
{


    return 0;
}