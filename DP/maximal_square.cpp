#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int mx = INT_MIN;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0||j==0) dp[i][j]=matrix[i][j]-'0';
                else if(matrix[i][j]=='0') dp[i][j]=0;
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                mx = max(mx, dp[i][j]);
            }
        }
        
        return mx*mx;
    }
};

int main()
{


    return 0;
}