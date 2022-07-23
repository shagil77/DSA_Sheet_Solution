#include <bits/stdc++.h>
using namespace std;

bool isCycleUtilDFS(int vertex, int parent, vector<bool> &vis, vector<int> adj[])
{
    vis[vertex] = true;

    for (auto it : adj[vertex])
    {
        if (!vis[it])
        {
            if (isCycleUtilDFS(it, vertex, vis, adj))
                return true;
        }
        else if (parent != it)
            return true;
    }

    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCycleUtilDFS(i, -1, visited, adj))
                return true;
        }
    }

    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> *adj;
    adj = new vector<int>[v];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isCycle(v, adj);

    return 0;
}