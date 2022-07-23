#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distTo(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        distTo[S]=0;
        pq.push(make_pair(0,S));
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]) {
                int nextNode = it[0];
                int nextDist = it[1];
                if(distTo[nextNode]>dist+nextDist) {
                    distTo[nextNode] = dist+nextDist;
                    pq.push(make_pair(distTo[nextNode], nextNode));
                }
            }
            // for(int i=0; i<adj[node].size(); i++) {
            //     int nextNode = i;
            //     int nextDist = adj[node][i];
            //     if(distTo[nextNode]>dist+nextNode) {
            //         distTo[nextNode] = dist+nextNode;
            //         pq.push(make_pair(distTo[nextNode], nextNode));
            //     }
            // }
        }
        
        return distTo;
    }


int main()
{
    vector<vector<int>> adj[5];

    

    return 0;
}