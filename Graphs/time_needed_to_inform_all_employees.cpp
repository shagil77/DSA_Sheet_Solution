#include<bits/stdc++.h>
using namespace std;

class Solution {
    int totalTimeBFS(int head, vector<int> adj[], vector<int> informTime) {
        queue<int> q;
        q.push(head);
        
        int ans=0;
        
        while(!q.empty()) {
            int maxTime=0;
            int size=q.size();
            
            for(int i=0; i<size; i++) {
                int manager=q.front();
                q.pop();
                
                if(adj[manager].size()!=0) maxTime = max(maxTime, informTime[manager]);
                // carru out recursion to find the max time
                
                for(auto subordinate:adj[manager]) {
                    q.push(subordinate);
                }
            }
            
            ans+=maxTime;
        }
        
        return ans;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        
        return totalTimeBFS(headID, adj, informTime);
    }
};



int main()
{


    return 0;
}