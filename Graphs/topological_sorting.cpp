#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

int main()
{
    int v, e;
    cin >> e >> v;
    vector<int> adj[v];

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> a = topoSort(v, adj);
    for(auto it:a) cout<<it<<" ";

    return 0;
}