#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    void dfs(string start, string end, double &val, bool &found, map<string,int> &vis, map<string, vector<string>> graph, map<string, double> edge) {
        vis[start]=1;
        
        if(found) return;
        
        for(auto curr:graph[start]) {
            if(vis[curr]!=1) {
                val*=edge[start+"->"+curr];
                
                if(curr==end) {
                    found=true;
                    return;
                } 
                
                dfs(curr,end,val,found,vis,graph,edge);
                
                if(found) return;
                else val/=edge[start+"->"+curr];
            }
        }
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int e=values.size();
        
        map<string, vector<string>> graph;
        map<string, double> edge;
        
        vector<double> ans;
        
        for(int i=0; i<e; i++) {
            string u=equations[i][0], v=equations[i][1];
            
            edge[u+"->"+v]=values[i];
            edge[v+"->"+u]=1/values[i];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(auto q:queries) {
            string start=q[0], end=q[1];
            
            if(graph[start].empty()||graph[end].empty()) {
                ans.push_back(-1);
                
            } else {
                map<string,int> vis;
                bool found=false;
                double val=1.0;
                
                if(start==end) found=true;
                else dfs(start, end, val, found, vis, graph, edge);
                
                if(found==true) {
                    ans.push_back(val);
                } else {
                    ans.push_back(-1);
                }
                
            }
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}