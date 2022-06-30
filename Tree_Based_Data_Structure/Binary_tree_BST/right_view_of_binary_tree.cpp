#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode *A)
{
    vector<int> ans;
    queue<TreeNode *> q1, q2;
    q1.push(A);

    while (!q1.empty())
    {
        TreeNode *curr = q1.front();
        q1.pop();
        
        if (curr->left == NULL && curr->right!=NULL)
        {
            q2.push(curr->right);
        }
        else if (curr->right == NULL && curr->left!=NULL)
        {
            q2.push(curr->left);
        }
        else if(curr->left!=NULL && curr->right!=NULL)
        {
            q2.push(curr->left);
            q2.push(curr->right);
        }

        if (q1.empty())
        {
            ans.push_back(curr->val);
            queue<TreeNode *> t;
            t=q1;
            q1 = q2;
            q2 = t;
        }

    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    vector<int> ans = solve(root);

    for (auto it : ans)
        cout << it << " ";

    return 0;
}