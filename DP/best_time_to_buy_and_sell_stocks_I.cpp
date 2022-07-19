#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int maxProfit(const vector<int> &A) {
    int n1=A.size();
    if(n1==0 || n1==1) return 0;
    int dp[n1];
    
    dp[0]=0;
    int mn=A[0];
    
    for(int i=1;i<n1;i++) {
        dp[i]=max(dp[i-1], A[i]-mn);
        mn=min(mn,A[i]);
    }
    
    return dp[n1-1];
}


int main()
{


    return 0;
}