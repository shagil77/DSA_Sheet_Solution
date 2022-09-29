#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    
    int solve(int e, int n) {
        if(e==0 || n==0) return 0;
        if(e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        
        int ans = INT_MAX;
        
        /* Linear Search will give TLE
        for(int k=1; k<=n; k++) {
            int temp = 1 + max((dp[e-1][k-1]!=-1)?dp[e-1][k-1]:solve(e-1, k-1),
                                (dp[e][n-k]!=-1)?dp[e][n-k]:solve(e, n-k));
            ans = min(ans, temp);
        }*/
        
        int l=1, h=n;
        while(l<=h) {
            int k = (l+h)/2;
            int down = (dp[e-1][k-1]!=-1)?dp[e-1][k-1]:solve(e-1, k-1);
            int top = (dp[e][n-k]!=-1)?dp[e][n-k]:solve(e, n-k);
            
            int temp = 1 + max(top, down);
            
            if(down<top) l = k+1;
            else h = k-1;
            
            ans = min(ans, temp);
        }
        
        return (dp[e][n] = ans);
    }
public:
    int superEggDrop(int k, int n) {
        // k = no of eggs
        // n  =no of floors
        dp.resize(k+1, vector<int>(n+1, -1));
        
        return solve(k,n);
    }
};



int main()
{


    return 0;
}