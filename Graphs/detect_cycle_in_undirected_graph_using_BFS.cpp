#include <bits/stdc++.h>
using namespace std;

bool isCycleUtilBFS(int vertex, vector<bool> &visited, vector<int> adj[]) {
    queue<pair<int,int>> q;
    q.push(make_pair(vertex,-1));
    visited[vertex]=true;

    while(!q.empty()) {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto it:adj[node]) {
            if(!visited[it]) {
                visited[it]=true;
                q.push(make_pair(it,node));
            } else if(parent!=it) {
                return true;
            }
        }
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
            if (isCycleUtilBFS(i, visited, adj))
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}