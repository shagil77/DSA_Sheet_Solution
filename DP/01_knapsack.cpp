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

int getMaximumNutrition(int m, vector<int> price, vector<int> nutrition, int k) {
    int n=price.size();
    
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            for(int l=0; l<=k; l++) {
                if(i==0||j==0||l==0) dp[i][j][l] = 0;
                else if(price[i-1]<=j) dp[i][j][l] = max(nutrition[i-1]+max(dp[i-1][j-price[i-1]][l],dp[i-1][j-(price[i-1]/2)][l-1]), dp[i-1][j][l]);
                else if((price[i-1]/2)<=j) dp[i][j][l] = max(nutrition[i-1] + dp[i-1][j-(price[i-1]/2)][l-1], dp[i-1][j][l]);
                else dp[i][j][l] = dp[i-1][j][l];
            }
        }
    }
    
    return dp[n][m][k];
}

int main()
{


    return 0;
}