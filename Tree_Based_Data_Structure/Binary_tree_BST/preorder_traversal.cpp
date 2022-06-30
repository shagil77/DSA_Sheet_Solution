#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(A);

    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();

        if (curr->left == NULL && curr->right == NULL)
        {
            ans.push_back(curr->val);
        }
        else if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            st.push(curr->right);
        }
        else if (curr->right == NULL)
        {
            ans.push_back(curr->val);
            st.push(curr->left);
        }
        else
        {
            ans.push_back(curr->val);
            st.push(curr->right);
            st.push(curr->left);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> ans = preorderTraversal(root);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}