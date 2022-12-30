#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> tree;
    vector<int> count;
    vector<int> res;

    void postorder(int root, int pre) {
        for(auto i:tree[root]) {
            if(i==pre) continue;
            postorder(i, root);
            count[root]+=count[i];
            res[root]+=res[i]+count[i];
        }
        count[root]++;
    }

    void preorder(int root, int pre) {
        for(auto i:tree[root]) {
            if(i==pre) continue;
            res[i]=res[root]-count[i]+count.size()-count[i];
            preorder(i, root);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        count.resize(n,0);
        res.resize(n,0);

        for(auto edge:edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        postorder(0, -1);
        preorder(0, -1);

        return res;
    }
};



int main()
{


    return 0;
}