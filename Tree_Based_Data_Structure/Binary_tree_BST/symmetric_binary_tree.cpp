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

static int isPal(vector<int> vi)
{
    int n = vi.size();

    for (int i = 0; i < (n / 2); i++)
    {
        if (vi[i] != vi[n - 1 - i])
            return 0;
    }
    return 1;
}
int isSymmetric(TreeNode *A)
{
    queue<TreeNode *> q1, q2;
    vector<int> vi;

    q1.push(A);

    while (!q1.empty())
    {
        TreeNode *curr = q1.front();
        q1.pop();

        if (curr == NULL)
            vi.push_back(-1);
        else
        {
            if (curr->left != NULL || curr->right != NULL)
            {
                q2.push(curr->left);
                q2.push(curr->right);
            }

            vi.push_back(curr->val);
        }

        if (q1.empty())
        {
            queue<TreeNode *> t;
            t = q1;
            q1 = q2;
            q2 = t;

            if (isPal(vi) == 0)
                return 0;
            vi.clear();
        }
    }
    return 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);

    cout << isSymmetric(root);

    return 0;
}