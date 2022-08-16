#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m=1e9 + 7;
    vector<int> adj[10];
    vector<vector<int>> dp;
    
    int countNums(int start, int level, int target) {
        if(level==target) return 1;
        if(dp[start][level]!=-1) return dp[start][level];
        
        int nums=0;
        for(auto it:adj[start]) {
            nums=(nums+countNums(it, level+1, target))%m;
        }
        return (dp[start][level]=nums%m);
    }
public:
    int knightDialer(int n) {
        dp.resize(10, vector<int>(n+1, -1));
        adj[0].push_back(4);
        adj[0].push_back(6);
        
        adj[1].push_back(6);
        adj[1].push_back(8);
        
        adj[2].push_back(7);
        adj[2].push_back(9);
        
        adj[3].push_back(4);
        adj[3].push_back(8);
        
        adj[4].push_back(0);
        adj[4].push_back(3);
        adj[4].push_back(9);
        
        adj[6].push_back(0);
        adj[6].push_back(1);
        adj[6].push_back(7);
        
        adj[7].push_back(2);
        adj[7].push_back(6);
        
        adj[8].push_back(1);
        adj[8].push_back(3);
        
        adj[9].push_back(2);
        adj[9].push_back(4);
        
        int ans=0;
        for(int i=0; i<=9; i++) {
            ans=(ans+countNums(i,1,n))%m;
        }
        
        return ans%m;
    }
};

int main()
{
    Solution s;
    cout<<s.knightDialer(3131);

    return 0;
}