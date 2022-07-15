#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

int longestValidParentheses(string A) {
    int n=A.length();
    int dp[n][n]={0};
    
    for(int j=0; j<n; j++) {
        int k=j, i=0;
        while(k<n) {
            if(k-i+1==1) dp[i][k]=0;
            else if(k-i+1==2) {
                if(A[i]=='(' && A[k]==')') dp[i][k]=2;
                else dp[i][k]=0;
            }
            else {
                dp[i][k]=dp[i][k-1]+dp[i+1][k]-dp[i+1][k-1];
                // 0 2     0 1         1 2       
            }
            i++;
            k++;
        }
    }

    rep(i,0,n) {
        rep(j,0,n) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return dp[0][n-1];
}

int main()
{
    cout<<longestValidParentheses(")())())()");

    return 0;
}