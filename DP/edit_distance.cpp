#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int minDistance(string A, string B) {
    int m=A.length(), n=B.length();
    
    int dp[m+1][n+1]={0};
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else {
                if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    
    return dp[m][n];
}

int main()
{

    cout<<minDistance("bbbaabaa", "aababbabb");
    return 0;
}