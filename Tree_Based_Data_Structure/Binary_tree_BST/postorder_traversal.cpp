#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *A)
{
    vector<int> ans;
    unordered_map<TreeNode *, bool> mp;
    stack<TreeNode *> st;
    st.push(A);

    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();


        if (curr->left == NULL && curr->right == NULL)
        {
            ans.push_back(curr->val);
            mp[curr]=true;
        }
        else if (curr->left == NULL)
        {
            if(mp[curr->right]) {
                ans.push_back(curr->val);
                mp[curr]=true;
            } else {
                st.push(curr);
                st.push(curr->right);
            }
        }
        else if (curr->right == NULL)
        {
            if(mp[curr->left]) {
                ans.push_back(curr->val);
                mp[curr]=true;
            } else {
                st.push(curr);
                st.push(curr->left);
            }
        }
        else
        {
            if(mp[curr->left] && mp[curr->right]) {
                ans.push_back(curr->val);
                mp[curr]=true;
            } else if(mp[curr->left]) {
                st.push(curr);
                st.push(curr->right);
            } else if(mp[curr->right]) {
                st.push(curr);
                st.push(curr->left);
            } else {
                st.push(curr);
                st.push(curr->right);
                st.push(curr->left);
            }
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> ans = postorderTraversal(root);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}