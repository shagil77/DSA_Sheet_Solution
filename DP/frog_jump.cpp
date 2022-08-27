#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> mp;
    vector<vector<int>> dp;
    bool solve(int i, int k, vector<int>& stones) {
        int n=stones.size();
        
        if(i>=n) return false;
        if(i==n-1) return true;
        
        
        if(dp[i][k]!=-1) return dp[i][k];
        
        for(int step=-1; step<=1; step++) {
            if(mp[stones[i]+k+step]!=0 && mp[stones[i]+k+step]>i) {
                if(solve(mp[stones[i]+k+step], k+step, stones)) return dp[i][k]=true;
            }
        }
        
        return dp[i][k]=false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.resize(2000, vector<int>(2000,-1));
        
        for(int i=0; i<n; i++) mp[stones[i]]=i;
        
        if(stones[1]!=1) return false;
        
        return solve(1,1,stones);
    }
};

int main()
{
    Solution s;
    vector<int> v = {0,1,3,5,6,8,12,17};
    s.canCross(v);

    return 0;
}