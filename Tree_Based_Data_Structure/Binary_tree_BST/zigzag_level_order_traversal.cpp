#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *A)
{
    vector<vector<int>> ans;
    vector<int> vi;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(A);
    bool leftToRight = true;

    while (!s1.empty() || !s2.empty())
    {

        TreeNode *curr = s1.top();
        s1.pop();

        if (leftToRight)
        {
            if (curr->left != NULL)
                s2.push(curr->left);
            if (curr->right != NULL)
                s2.push(curr->right);
        }
        else
        {
            if (curr->right != NULL)
                s2.push(curr->right);
            if (curr->left != NULL)
                s2.push(curr->left);
        }
        vi.push_back(curr->val);

        if (s1.empty())
        {
            stack<TreeNode *> t;
            t = s1;
            s1 = s2;
            s2 = t;
            ans.push_back(vi);
            vi.clear();
            leftToRight = !leftToRight;
        }
    }
    return ans;
}

int main()
{

    return 0;
}