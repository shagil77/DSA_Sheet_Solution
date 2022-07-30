//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool DFS(int node, int parent, int &timer, vector<int> adj[], vector<bool> &vis, 
            vector<int> &tin, vector<int> &low, vector<int> &isArticulation) {
        
        tin[node]=low[node]=(++timer);
        vis[node]=true;
        int child=0;
        
        for(auto it:adj[node]) {
            if(it==parent) continue;
            
            if(!vis[it]) {
                DFS(it, node, timer, adj, vis, tin, low, isArticulation);
                low[node] = min(low[it], low[node]);
                child++;
                
                
                if(parent!=-1 && low[it] >= tin[node]) {
                    isArticulation[node]=1;
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(parent==-1 && child>1) isArticulation[node]=1;
    }
    int biGraph(int arr[], int n, int e) {
        // code here
        /*if(e==1) return 0;*/
        vector<int> adj[n];
        vector<bool> vis(n, false);
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<int> isArticulation(n,0);
        int timer=0;
        
        for(int i=0; i<2*e; i+=2) {
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        DFS(0, -1, timer, adj, vis, tin, low, isArticulation);
        for(int i=0; i<n; i++) {
            if(isArticulation[i]==1) {
                return false;
            }
        }
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}
// } Driver Code Ends