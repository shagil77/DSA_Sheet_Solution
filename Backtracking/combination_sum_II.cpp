#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    int n;
    
    void solve(int idx, int target, vector<int> &arr, vector<int>& v) {
        
        if(target==0) {
            ans.push_back(v);
            return;
        } else {
            for(int i=idx; i<n; i++) {
                if(arr[i]>target) return;
                if(i && arr[i]==arr[i-1] && i>idx) continue;
                
                v.push_back(arr[i]);
                solve(i+1, target-arr[i], arr, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        
        solve(0, target, candidates, v);
        
        return ans;
    }
};

int main()
{


    return 0;
}