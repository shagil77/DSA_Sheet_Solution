#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, vector<bool> &vis, vector<bool> &dfsvis, vector<int> adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCyclicDFS(it, vis, dfsvis, adj))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> dfsvis(V, false);

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(isCyclicDFS(i, vis, dfsvis, adj)) return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}