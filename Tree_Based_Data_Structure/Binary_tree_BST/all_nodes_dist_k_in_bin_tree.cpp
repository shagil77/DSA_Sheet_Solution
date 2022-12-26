#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> distKNodes;
    unordered_map<TreeNode*, bool> visited;
    
    void findNodes1(TreeNode* root, int k) { // To find distance K nodes in forest of root
        if(root == NULL) return;
        if(k==0) {
            distKNodes.push_back(root->val);
            return;
        }

        findNodes1(root->left, k-1);
        findNodes1(root->right, k-1);
    }
    void findNodes2(TreeNode* root, int k) { 
        if(root==NULL) return;
        if(visited[root]) return;
        if(k==0) {
            visited[root] = true;
            distKNodes.push_back(root->val);
            return;
        }
        findNodes2(root->left, k-1);
        findNodes2(root->right, k-1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parentOf; // child, parent
        
        q.push(root);
        while(!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();

            if(currentNode->left != NULL) {
                parentOf[currentNode->left] = currentNode;
                q.push(currentNode->left);
            }
            if(currentNode->right != NULL) {
                parentOf[currentNode->right] = currentNode;
                q.push(currentNode->right);
            }
        }
        findNodes1(target, k);
        TreeNode* curr = target;
        visited[target] = true;
        for(int dist=1; dist<=k && curr!=NULL; dist++) {
            visited[curr] = true;
            curr = parentOf[curr];
            findNodes2(curr, k-dist);
        }

        return distKNodes;
    }
};

int main()
{


    return 0;
}