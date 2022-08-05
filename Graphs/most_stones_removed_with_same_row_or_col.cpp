#include<bits/stdc++.h>
using namespace std;

class Solution {
    class DisjointSet {
        
        int N;
        vector<int> parent;
        vector<int> rank;
        
        public:
        DisjointSet(int n) {
            N=n;
            parent.resize(N);
            rank.resize(N);
            
            for(int i=0; i<N; i++) {
                parent[i]=i;
                rank[i]=0;
            }
        }
        
        int findParent(int node) {
            if(node==parent[node]) return node;
            
            return (parent[node]=findParent(parent[node]));
        }
        
        void Union(int u, int v) {
            u=findParent(u);
            v=findParent(v);
            
            if(rank[u]<rank[v]) {
                parent[u]=v;
            } else if(rank[u]>rank[v]) {
                parent[v]=u;
            } else {
                parent[v]=u;
                rank[u]++;
            }
        }
        
        int countDisjointSets() {
            unordered_map<int,int> mp;
            for(int i=0; i<N; i++) {
                parent[i]=findParent(i);
                mp[parent[i]]++;
                // cout<<parent[i]<<"\n";
            }
            return mp.size();
        }

        
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) {
                    ds.Union(i,j);
                }
            }
        }
        
        return (n-ds.countDisjointSets());
    }
};


int main()
{
    vector<vector<int>> stones = {{0,1},{1,2},{1,3},{3,3},{2,3},{0,2}};
    Solution s;

    cout<<s.removeStones(stones);

    return 0;
}