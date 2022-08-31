#include<bits/stdc++.h>
using namespace std;

class Solution {
    /* Method I (Correct)
    vector<vector<int>> dp;
    int solve(int idx, int buy, vector<int>& prices, int n) {
        
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        if(buy==1) return dp[idx][buy] = max(-prices[idx]+solve(idx+1, 0, prices, n),
                                            0 + solve(idx+1, 1, prices, n));
        return dp[idx][buy] = max(prices[idx] + solve(idx+1, 1, prices, n),
                                 0 + solve(idx+1, 0, prices, n));
    }*/
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        /* Method II (Correct)
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy==1) dp[i][buy] = max(-prices[i]+dp[i+1][0],
                                                0 + dp[i+1][1]);
                else dp[i][buy] = max(prices[i] + dp[i+1][1],
                                        0 + dp[i+1][0]);
            }
        }*/
        
        // Method III
        vector<int> ahead(2,0);
        vector<int> cur(2,0);
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy==1) cur[buy] = max(-prices[i]+ahead[0], 0 + ahead[1]);
                else cur[buy] = max(prices[i] + ahead[1], 0 + ahead[0]);
                
                ahead[buy] = cur[buy];
            }
        }
        
        return cur[1];
    }
};

int main()
{


    return 0;
}