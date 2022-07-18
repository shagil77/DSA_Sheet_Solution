#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

vector<int> dp(100,-1);

int solve(vector<vector<int>> &A) {
    int n=A[0].size();
    dp[0]=max(A[0][0], A[1][0]);
    dp[1]=max(dp[0], max(A[0][1], A[1][1]));

    for(int i=2; i<n; i++) {
        int temp1=dp[i-2]+max(A[0][i], A[1][i]);
        int temp2=max(dp[i-1], max(A[0][i], A[1][i]));
        dp[i]=max(temp1, temp2);
    }

    return dp[n-1];

}

int main()
{
    vector<vector<int>> a={{16, 5, 54, 55, 36, 82, 61, 77, 66, 61}, {31, 30, 36, 70, 9, 37, 1, 11, 68, 14}};

    cout<<solve(a);

    return 0;
}