#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

long long int count(int S[], int m, int n) {

        // code here.
        long long int dp[m+1][n+1];
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 && j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(j==0) dp[i][j]=1;
                else {
                    if(S[i-1]<=j) dp[i][j]=dp[i][j-S[i-1]] + dp[i-1][j];
                    else dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }

int main()
{


    return 0;
}