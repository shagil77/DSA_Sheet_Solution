#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        set<int> s(nums.begin(), nums.end());
        vector<int> nums2(s.begin(), s.end());
        sort(nums2.begin(), nums2.end());
        int m=nums2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(nums[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};

int main()
{


    return 0;
}
