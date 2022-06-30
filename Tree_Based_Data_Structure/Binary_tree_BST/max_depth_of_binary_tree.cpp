#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* A) {
    if(A->left==NULL && A->right==NULL) return 1;

    if(A->left==NULL) {
        return (maxDepth(A->right)+1);
    }

    if(A->right==NULL) {
        return (maxDepth(A->left)+1);
    }

    return (1+max(maxDepth(A->left), maxDepth(A->right)));
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout<<maxDepth(root);
    return 0;
}