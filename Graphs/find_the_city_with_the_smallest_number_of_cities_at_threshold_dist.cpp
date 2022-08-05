#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 100000000));
        
        for(auto it: edges) {
            int from=it[0], to=it[1], wt=it[2];
            
            adj[from][to]=wt;
            adj[to][from]=wt;
        }
        
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i==k||j==k||i==j) continue;
                    
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        
        int ans=INT_MAX, city;
        for(int i=0; i<n; i++) {
            int c=0;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(adj[i][j]<=distanceThreshold) c++;
            }
            if(c<ans) {
                city=i;
                ans=c;
            }
            else if(c==ans) {
                city=max(city,i);
            }
        }
        
        return city;
    }
};

int main()
{


    return 0;
}