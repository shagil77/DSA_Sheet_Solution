#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans=1;
    int r,c;
    vector<vector<int>> dp;
    vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    
    void bfs(int i, int j, vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()) {
            int x=q.front().first, y=q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int x1=x+dir[i].first, y1=y+dir[i].second;
                
                if(x1>=0 && y1>=0 && x1<r && y1<c && matrix[x][y]<matrix[x1][y1]) {
                    if(dp[x1][y1]<1+dp[x][y]) {
                        dp[x1][y1]=1+dp[x][y];
                        ans=max(ans,dp[x1][y1]);
                        q.push({x1,y1});
                    }
                }
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r=matrix.size(), c=matrix[0].size();
        dp.resize(r, vector<int>(c,1));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                bfs(i,j,matrix);
            }
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}