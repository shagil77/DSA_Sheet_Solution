#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<vector<int>, int> mp;
    int c=0;
    
    void findAllCutEdges(int source, int parent, vector<int> adj[], vector<int> &vis, vector<int> &low, vector<int> &disc) {
        vis[source]=1;
        c++;
        low[source]=disc[source]=c;
        
        for(auto child:adj[source]) {
            if(child==parent) continue;
            
            if(!vis[child]) {
                findAllCutEdges(child, source, adj, vis, low, disc);
                
                low[source]=min(low[source], low[child]);
                if(low[child]>disc[source] && (mp[{child,source}]==0 && mp[{source,child}]==0)) {
                    mp[{child,source}]++;
                }
            } else {
                low[source]=min(low[source],low[child]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<int> vis(n,0);
        
        for(auto it:connections) {
            int u=it[0], v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> criticalEdges;
        
        findAllCutEdges(0,-1,adj,vis,low,disc);
        
        for(auto it:mp) {
            if(it.second) criticalEdges.push_back(it.first);
        }

        
        
        return criticalEdges;
    }
};

int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{1,3}};
    Solution s;
    vector<vector<int>> ans = s.criticalConnections(4,edges);

    for(auto it:ans) {
        cout<<it[0]<<" "<<it[1]<<"\n";
    }

    return 0;
}