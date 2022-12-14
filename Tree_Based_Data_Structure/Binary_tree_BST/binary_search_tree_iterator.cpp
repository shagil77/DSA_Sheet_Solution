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

class BSTIterator {
    vector<int> inorder;
    int N;
    int curr = -1;
    int DEF_VAL = -1;
    void inorderTraversal(TreeNode* root) {
        if(root==NULL) return;

        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        N = inorder.size();
    }
    
    int next() {
        curr++;
        return inorder[curr];
    }
    
    bool hasNext() {
        return (curr+1<N);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{


    return 0;
}