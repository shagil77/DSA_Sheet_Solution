#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    bool unionNodes(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if(u==v) return false;
        if(rank[u]>rank[v]) parent[v] = u;
        else if(rank[u]<rank[v]) parent[u]=v;
        else {
            parent[u]=v;
            rank[v]++;
        }
        return true;
    }
    bool inSameComponent(int u, int v) {
        return findParent(u)==findParent(v);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2);
        for(int i=1; i<=edges.size(); i++) parent[i]=i;

        for(auto edge:edges) {
            if(!unionNodes(edge[0], edge[1])) {
                return edge;
            }
        }

        return ans;
    }
};

int main()
{


    return 0;
}