#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
static void solve(TreeNode *A, int B, vector<vector<int>> &ans, vector<int> path) {
    if(!A) return;
    if(!A->left && !A->right) {
        path.push_back(A->val);
        if(A->val==B) ans.push_back(path);
        return;
    }
    path.push_back(A->val);
    solve(A->left,B-(A->val), ans, path);
    solve(A->right, B-(A->val), ans, path);
}

vector<vector<int> > pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> path;
    solve(A, B, ans, path);
    return ans;
}

int main()
{
    

    return 0;
}