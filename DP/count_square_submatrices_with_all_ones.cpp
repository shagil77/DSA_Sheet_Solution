#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0||j==0) dp[i][j]=matrix[i][j];
                else if(matrix[i][j]==0) dp[i][j]=0;
                else dp[i][j]=matrix[i][j]+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        
        int sum=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sum+=dp[i][j];
            }
        }
        
        return sum;
    }
};

int main()
{


    return 0;
}