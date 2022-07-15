#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

string dp[1001][1001]={""};
int dp2[1001][1001] = {0};

string longestCommonSubsequence(string x, string y, int n, int m) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0||j==0) dp[i][j]="";
            else {
                if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+x[i-1];
                else {
                    if(dp[i-1][j].length()>dp[i][j-1].length()) dp[i][j]=dp[i-1][j];
                    else dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}

string longestCommonSubsequence2(string x, string y, int n, int m) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0||j==0) dp2[i][j]=0;
            else {
                if(x[i-1]==y[j-1]) dp2[i][j]=dp2[i-1][j-1]+1;
                else dp2[i][j]=max(dp2[i-1][j], dp2[i][j-1]);
            }
        }
    }

    string ans="";
    int i=n, j=m;
    while(i>0 && j>0) {
        if(x[i-1]==y[j-1]) {
            ans=x[i-1]+ans;
            i--;
            j--;
        } else {
            if(dp2[i-1][j]>dp2[i][j-1]) i--;
            else j--;
        }
    }

    return ans;
}

int main()
{
    string x="AGGTAB", y="GXTXAYB";
    cout<<longestCommonSubsequence2(x, y, x.length(), y.length());
    return 0;
}