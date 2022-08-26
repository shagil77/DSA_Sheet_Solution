#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        vector<int> arr;
        
        for(auto num:nums) mp[num]++;
        
        for(auto p:mp) arr.push_back(p.first);
        int n=arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n, 0);
        dp[0] = arr[0]*mp[arr[0]];
        
        if(n==1) return dp[0];
        
        if(arr[1] == arr[0]+1) dp[1] = max(arr[1]*mp[arr[1]], dp[0]);
        else dp[1] = dp[0] + arr[1]*mp[arr[1]];
        
        for(int i=2; i<n; i++) {
            if(arr[i] == arr[i-1]+1) dp[i] = max(dp[i-2] + arr[i]*mp[arr[i]], dp[i-1]);
            else dp[i] = dp[i-1] + arr[i]*mp[arr[i]];
        }
        
        return dp[n-1];
    }
};

int main()
{


    return 0;
}