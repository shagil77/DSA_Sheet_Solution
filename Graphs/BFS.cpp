#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> bfs;
    vector<bool> visited(V, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int curr=q.front();
        q.pop();

        bfs.push_back(curr);

        for(int i=0; i<adj[curr].size(); i++) {
            if(!visited[adj[curr][i]]) {
                visited[adj[curr][i]]=true;
                q.push(adj[curr][i]);
            }
        }
    }

    return bfs;
}


int main()
{


    return 0;
}