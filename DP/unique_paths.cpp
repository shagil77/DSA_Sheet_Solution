#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int dfs(int x, int y, int m, int n) {
        if(x==m && y==n) return 1;
        if(x<1 || x>m || y<1 || y>n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        
        return (dp[x][y] = dfs(x,y+1,m,n)+dfs(x+1,y,m,n));
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m+1, vector<int>(n+1,-1));
        return dfs(1,1,m,n);
    }
};

int main()
{


    return 0;
}