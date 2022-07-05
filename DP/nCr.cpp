#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int nCr(int n, int r){
        // code here
        int m=(int)1e9 + 7;
        int dp[n+1][r+1]={0};
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=i && j<=r; j++) {
                if(j==0 || i==j) dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%m;
            }
        }
        return dp[n][r]%m;
    }

int main()
{


    return 0;
}