#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        
        int target = sum/2;
        vector<vector<int>> dp(N+1, vector<int>(target+1, 0));
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=target; j++) {
                if(arr[i-1]==j) dp[i][j] = 1;
                else if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[N][target];
    }

int main()
{
    int arr[] = {1,5,11,5};
    cout<<equalPartition(4, arr)<<"\n";

    return 0;
}