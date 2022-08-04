//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfs1(int source, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
        vis[source] = 1;
        for(auto v:adj[source]) {
            if(vis[v]) continue;
            
            dfs1(v, st, vis, adj);
        }
        st.push(source);
    }
    void dfs2(int source, vector<int> &vis, vector<int> adj[]) {
        vis[source] = 1;
        
        for(auto v:adj[source]) {
            if(vis[v]) continue;
            
            dfs2(v, vis, adj);
        }
        
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> revAdj[V];
        for(int i=0; i<V; i++) {
            for(auto it:adj[i]) {
                revAdj[it].push_back(i);
            }
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) dfs1(i,st,vis,adj);
        }
        
        
        int count=0;
        
        vector<int> vis2(V,0);
        vector<int> scc(V,0);
        while(!st.empty()) {
            int node=st.top();
            st.pop();
            
            if(!vis2[node]) {
                dfs2(node, vis2, revAdj);
                count++;
            }
            
            
        }

        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends