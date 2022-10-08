#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> grid;
    vector<vector<string>> ans;
    int N;
    
    bool isSafe(int row, int col) {
        int r, c;
        r=row;
        while(r>=0) {
            if(grid[r][col]) return false;
            r--;
        }
        
        c = col;
        while(c>=0) {
            if(grid[row][c]) return false;
            c--;
        }
        
        r=row;
        c=col;
        while(r>=0 && c>=0) {
            if(grid[r][c]) return false;
            r--;
            c--;
        }
        
        r=row;
        c=col;
        while(r>=0 && c<N) {
            if(grid[r][c]) return false;
            c++;
            r--;
        }
        
        return true;
    }
    
    void solve(int row) {
        if(row==N) {
            pushConfig();
            return;
        }
        for(int col=0; col<N; col++) {
            if(isSafe(row, col)) {
                grid[row][col] = 1;
                solve(row+1);
                grid[row][col] = 0;
            }
        }
    }
    
    void pushConfig() {
        vector<string> v;
        for(int i=0; i<N; i++) {
            string s="";
            for(int j=0; j<N; j++) {
                if(grid[i][j]==0) s+="."; 
                else s+="Q";
            }
            v.push_back(s);
        }
        ans.push_back(v);
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<int>(n,0));
        N = n;
        
        solve(0);
        
        return ans;
    }
};

int main()
{


    return 0;
}