#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int cost = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;
    pq.push(make_pair(0, 0)); // key[v], v

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];

            if (mst[v] == false && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cost += key[i];
    }

    return cost;
}

int main()
{

    return 0;
}