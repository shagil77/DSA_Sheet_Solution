#include <bits/stdc++.h>
using namespace std;

void DFS(int s, vector<int> adj[], vector<bool> &explored, vector<int> &ans)
{
    explored[s] = true;
    ans.push_back(s);

    for (auto x : adj[s])
    {
        if (!explored[x])
        {
            DFS(x, adj, explored, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> dfs;
    vector<bool> explored(V, false);

    DFS(0, adj, explored, dfs);
    return dfs;
}

int main()
{

    return 0;
}