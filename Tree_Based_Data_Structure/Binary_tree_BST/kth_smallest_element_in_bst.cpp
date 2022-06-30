#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static void inorder(TreeNode* A, vector<int> &ans) {
    if(A==NULL) return;
    
    inorder(A->left, ans);
    ans.push_back(A->val);
    inorder(A->right, ans);
}
int kthsmallest(TreeNode* A, int B) {
    vector<int> ans;
    inorder(A, ans);
    
    return ans[B-1];
}

int main()
{


    return 0;
}