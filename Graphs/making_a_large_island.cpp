#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    
    
    void bfs(int i, int j, int c, int &size, vector<vector<int>>& comp, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        comp[i][j]=c;
        q.push({i,j});
        
        while(!q.empty()) {
            int x=q.front().first, y=q.front().second;
            q.pop();
            size++;
            
            for(int k=0; k<4; k++) {
                int xx=x+dir[k].first, yy=y+dir[k].second;
                
                if(xx>=0 && yy>=0 && xx<n && yy<n) {
                    if(grid[xx][yy]==1 && comp[xx][yy]==0) {
                        comp[xx][yy]=c;
                        q.push({xx,yy});
                    }
                }
            }
        }
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> comp(n,vector<int>(n,0));
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> wts;
        int c=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && comp[i][j]==0) {
                    c++;
                    int size=0;
                    bfs(i,j,c,size,comp,grid);
                    wts.push_back(size);
                }
            }
        }
        
        if(wts.size()==0) return 1;
        if(wts.size()==1) return min(wts[0]+1, n*n);
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(comp[i][j]==0) {
                    int temp=0;
                    unordered_map<int,int> mp;
                    for(int k=0; k<4; k++) {
                        int xx=i+dir[k].first, yy=j+dir[k].second;

                        if(xx>=0 && yy>=0 && xx<n && yy<n && comp[xx][yy]!=0 && mp[comp[xx][yy]]==0) {
                            temp+=wts[comp[xx][yy]-1];
                            mp[comp[xx][yy]]=1;
                        }
                    }
                    ans=max(ans,temp+1);
                }
            }
        }
        
        return ans;
    }
};


int main()
{
    vector<vector<int>> grid={{0,0,0,0,0,0,0},{0,1,1,1,1,0,0},{0,1,0,0,1,0,0},{1,0,1,0,1,0,0},{0,1,0,0,1,0,0},{0,1,0,0,1,0,0},{0,1,1,1,1,0,0}};
    Solution s;

    int n=grid.size();
    cout<<s.largestIsland(grid);
    

    return 0;
}