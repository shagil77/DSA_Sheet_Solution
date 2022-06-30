#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ans;
    unordered_map<TreeNode *, bool> mp;
    stack<TreeNode *> st;
    st.push(A);

    while(!st.empty()) {
        TreeNode* curr=st.top();
        st.pop();

        if(mp[curr]) ans.push_back(curr->val);
        else {
            if(curr->left==NULL && curr->right==NULL) {
                ans.push_back(curr->val);
            } else if(curr->left==NULL) {
                ans.push_back(curr->val);
                st.push(curr->right);
            } else if(curr->right==NULL) {
                st.push(curr);
                st.push(curr->left);
            } else {
                st.push(curr->right);
                st.push(curr);
                st.push(curr->left);
            }
        }

        mp[curr]=true;
    }
    return ans;
}

static TreeNode* solve(const vector<int> &A, int l, int r) {
    if(l<=r) {
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(A[m]);
        root->left=solve(A, l, m-1);
        root->right=solve(A,m+1,r);
        return root;
    }
    return NULL;
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    return solve(A, 0, A.size()-1);
}


int main()
{
    vector<int> A={1,2,3,4,5};
    vector<int> ans=inorderTraversal(sortedArrayToBST(A));

    for(auto it: ans) cout<<it<<" ";

    return 0;
}