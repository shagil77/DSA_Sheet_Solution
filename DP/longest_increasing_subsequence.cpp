#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int longestSubsequence(int n, int a[])
    {
       // your code here
       map<int,int> mp;
       for(int i=0;i<n;i++) mp[a[i]]++;
       
       vector<int> b;
       for(auto p:mp) {
           b.push_back(p.first);
       }
       
       int m=b.size();
       int dp[n+1][m+1]={0};
       
       for(int i=0; i<=n; i++) {
           for(int j=0;j<=m;j++) {
               if(i==0||j==0) dp[i][j]=0;
               else {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
               }
           }
       }
       
       return dp[n][m];
    }

int main()
{


    return 0;
}