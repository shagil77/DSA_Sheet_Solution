#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-k)%(k-1)!=0) return -1;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        vector<int> cumsum(n+1, 0);
        
        for(int i=0; i<n; i++) cumsum[i+1] = cumsum[i] + stones[i];
        
        for(int l=k-1; l<n; l++) {
            for(int x=0, y=x+l; x<n && y<n; x++, y++) {
                if(l==k-1) dp[x][y] = cumsum[y+1] -cumsum[x];
                else {
                    dp[x][y] = INT_MAX;
                    for(int mid = x; mid<y; mid+=k-1) {
                        dp[x][y] = min(dp[x][y], dp[x][mid]+dp[mid+1][y]);
                    }
                    if(l%(k-1)==0)
                        dp[x][y]+=cumsum[y+1]-cumsum[x];
                }
            }
        }
        
        return (dp[0][n-1]!=INT_MAX)?dp[0][n-1]:-1;
    }
};

int main()
{


    return 0;
}