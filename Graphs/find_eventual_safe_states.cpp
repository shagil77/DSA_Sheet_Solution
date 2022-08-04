#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(int s, vector<int> &vis, vector<vector<int>>& graph) {
        if(vis[s]!=0) return (vis[s]==1);
        vis[s]=2;

        for(auto v:graph[s]) {
            if(!isSafe(v, vis, graph)) return false;
        }
        vis[s]=1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, 0);
        // 0 - unvisited
        // 1- safe
        // 2 - visited

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(isSafe(i,vis,graph)) ans.push_back(i);
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph={{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> a= s.eventualSafeNodes(graph);

    for(auto it:a) cout<<it<<" ";

    return 0;
}