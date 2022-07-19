#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int maxProfit(const vector<int> &A) {
    int n=A.size();
    if(n==0||n==1) return 0;
    vector<int> dp(n,0);
    
    int mn=A[0];
    long long int ans=0;
    
    for(int i=0;i<n-1;i++) {
        if(A[i+1]>=A[i]) {
            dp[i+1]=max(dp[i],A[i+1]-mn);
            mn=min(mn,A[i+1]);
        } else {
            ans+=dp[i];
            mn=A[i+1];
        }
    }
    ans+=dp[n-1];
    return ans;
}


int main()
{


    return 0;
}