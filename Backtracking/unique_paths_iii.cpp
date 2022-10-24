#include<bits/stdc++.h>
using namespace std;

class Solution {
    int count, emptyCells, m, n;
    vector<vector<int>> DIR = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    void solve(int x, int y, vector<vector<int>>& grid, int markCount) {
        if(x<0 || x==m || y<0 || y==n || grid[x][y]==3 || grid[x][y]==-1) return;
        
        if(grid[x][y]==2) {
            if(markCount==emptyCells+1) count++;
            return;
        } 
        
        int curr = grid[x][y];
        grid[x][y] = 3;
        
        for(auto dir:DIR) solve(x+dir[0], y+dir[1], grid, markCount+1);
        
        grid[x][y] = curr;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        count = 0, emptyCells=0;
        int x=-1, y=-1;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    x = i;
                    y = j;
                }
                else if(grid[i][j]==0) emptyCells++;
            }
        }
        
        solve(x, y, grid, 0);
        
        return count;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> v = {{0,1},{2,0}};
    cout<<sol.uniquePathsIII(v)<<"\n";

    return 0;
}