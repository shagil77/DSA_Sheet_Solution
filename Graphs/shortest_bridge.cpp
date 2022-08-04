#include<bits/stdc++.h>
using namespace std;

class Solution {
    // used to push all 1's of the 1st island into the queue to run the BFS on them.
    void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int,int>> &q) {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==2 || grid[i][j]==0) return;

        grid[i][j]=2;
        q.push({i,j});

        dfs(i+1, j, grid, q);
        dfs(i-1, j, grid, q);
        dfs(i, j+1, grid, q);
        dfs(i, j-1, grid, q);
    }


    public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};

        queue<pair<int,int>> q;

        bool flag=false;
        for(int i=0; i<n && !flag; i++) {
            for(int j=0; j<n && !flag; j++) {
                if(grid[i][j]) {
                    dfs(i,j,grid,q);
                    flag=true;
                }
            }
        }

        int dist=0;
        while(!q.empty()) {
            dist++;
            int size=q.size();

            for(int i=0; i<size; i++) { // traversing layerwise in the matrix
                int x=q.front().first, y=q.front().second;
                q.pop();

                for(int k=0; k<4; k++) {
                    int nx=x+dir[k][0], ny=y+dir[k][1];

                    if((0<=nx && nx<n) && (0<=ny && ny<n) && (grid[nx][ny]==1)) {
                        return (dist-1);
                    }

                    if((0<=nx && nx<n) && (0<=ny && ny<n) && (grid[nx][ny]!=2)) {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> grid={{0,1,0}, {0,0,0}, {0,0,1}};
    Solution s;
    cout<<s.shortestBridge(grid);

    return 0;
}