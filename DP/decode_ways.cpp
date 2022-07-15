#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)


static int getCorrChar(string num) {
    if(num[0]=='0') return 0;
    if(stoi(num)<=26) return 1;
    return 0;
}

int numDecodings(string A) {
    int m=(int)1e9+7;
    int n=A.length();
    long long int dp[n];

    dp[0]=getCorrChar(A.substr(0,1));
    if(n>1) {
        dp[1]=getCorrChar(A.substr(1,1))*dp[0] + getCorrChar(A.substr(0,2));
        for(int i=2; i<n; i++) {
            dp[i]=(getCorrChar(A.substr(i,1))*dp[i-1] + getCorrChar(A.substr(i-1,2))*dp[i-2])%m;
        }
    }
    return dp[n-1]%m;
}


int main()
{
    cout<<numDecodings("123456789");

    return 0;
}