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
    TreeNode* solve(int low, int high, vector<int>& nums) {
        if(low>high) return NULL;
        if(low==high) return new TreeNode(nums[low]);
        
        int m = (low+high)/2;
        TreeNode* root = new TreeNode(nums[m]);
        
        root->left = solve(low, m-1, nums);
        root->right = solve(m+1, high, nums);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        
        return solve(low, high, nums);
    }
};

int main()
{


    return 0;
}