#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    map<vector<int>, int> mp;
    
    void solve(int idx, int n, vector<int>& nums, vector<int>& v) {
        if(mp[v]==0) {
            ans.push_back(v);
            mp[v]=1;
        }
        
        
        for(int i=idx; i<n; i++) {
            // if(i>idx && nums[i]==nums[i-1]) return;
            v.push_back(nums[i]);
            solve(i+1, n, nums, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        
        solve(0, nums.size(), nums, v);
        
        return ans;
    }
};

int main()
{


    return 0;
}