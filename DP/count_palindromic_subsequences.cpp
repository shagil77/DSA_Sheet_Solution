#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll countPalindromes(string s, int n) {
    vector<vector<ll>> dp(n, vector<ll>(n,0));

    for(int k=0; k<n; k++) {
        for(int i=0, j=k; i<n && j<n; i++, j++) {
            if(i>j) dp[i][j]=INT_MAX;
            else if(i==j) dp[i][j]=1;
            else if(j-i==1) {
                if(s[i]==s[j]) dp[i][j]=3;
                else dp[i][j]=2;
            }
            else {
                if(s[i]==s[j]) dp[i][j] = dp[i][j-1]+dp[i+1][j]+1;
                else dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    string s;
    cin>>s;

    int n = s.length();
    cout<<countPalindromes(s,n);
    
    return 0;
}