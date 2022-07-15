#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int calculateMinimumHP(vector<vector<int> > &A) {
    int m=A[0].size(), n=A.size();
    
    int dp[m][n]={0};
    
    for(int i=m-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            if(i==m-1 && j==n-1) {
                dp[i][j]=(A[i][j]<0)?A[i][j]:0;
            } else if(i==m-1) {
                int val=dp[i][j+1]+A[i][j];
                dp[i][j]=(val<0)?val:0;
            } else if(j==n-1) {
                int val=dp[i+1][j]+A[i][j];
                dp[i][j]=(val<0)?val:0;
            } else {
                int val=A[i][j] + max(dp[i][j+1], dp[i+1][j]);
                dp[i][j]=(val<0)?val:0;
            }
        }
    }

    return ((-1)*dp[0][0]+1);
}

int main()
{
    vector<vector<int>> A = {{-2,-3,3},
                             {-5,-10,1},
                             {10,30,-5}};

    cout<<calculateMinimumHP(A);

    return 0;
}