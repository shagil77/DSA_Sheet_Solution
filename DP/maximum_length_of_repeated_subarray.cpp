#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int mx=INT_MIN;
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) dp[i][j]=0;
                else if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
                
                mx=max(mx,dp[i][j]);
            }
        }
        
        return mx;
    }
};

int main()
{


    return 0;
}