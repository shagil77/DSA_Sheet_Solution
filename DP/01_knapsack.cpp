#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       
       for(int i=0; i<=n; i++) {
           for(int j=0; j<=W; j++) {
               if(i==0||j==0) {
                   dp[i][j]=0;
               } else if(wt[i-1]<=j) {
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
               } else {
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       
       return dp[n][W];
    }

int main()
{


    return 0;
}