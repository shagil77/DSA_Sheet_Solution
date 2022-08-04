#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int s, vector<bool> &vis, vector<int> adj[]) {
        vis[s]=true;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            
            for(auto v:adj[u]) {
                if(!vis[v]) {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
        if(e<n-1) return -1;
        
        vector<int> adj[n];
        vector<bool> vis(n, false);
        for(auto it:connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int connectedComponents=0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                bfs(i, vis, adj);
                connectedComponents++;
            }
        }
        
        return (connectedComponents-1);
    }
};

int main()
{


    return 0;
}