#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    /* Method I
    vector<vector<vector<int>>> dp;
    int solve(int idx, int buy, int k, vector<int>& prices, int n) {
        
        if(idx==n || k==0) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        
        if(buy==1) return dp[idx][buy][k] = max(-prices[idx]+solve(idx+1, 0, k, prices, n),
                                            0 + solve(idx+1, 1, k, prices, n));
        return dp[idx][buy][k] = max(prices[idx] + solve(idx+1, 1, k-1, prices, n),
                                 0 + solve(idx+1, 0, k, prices, n));
    }*/
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        /* Method II (Correct)
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy==1) dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap],
                                                        0 + dp[idx+1][1][cap]);
                    else dp[idx][buy][cap] = max(prices[idx] + dp[idx+1][1][cap-1],
                                                0 + dp[idx+1][0][cap]);
                }
            }
        }*/
        
        // Method III (Correct)
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy==1) curr[buy][cap] = max(-prices[idx]+ahead[0][cap],
                                                        0 + ahead[1][cap]);
                    else curr[buy][cap] = max(prices[idx] + ahead[1][cap-1],
                                                0 + ahead[0][cap]);
                    ahead[buy][cap] = curr[buy][cap];
                }
            }
        }
        
        return curr[1][k];
    }
};

int main()
{


    return 0;
}