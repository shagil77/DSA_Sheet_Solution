#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    
    void solve(int idx, int n, int k, vector<int> &v) {
        if(k==0 ) {
            ans.push_back(v);
        }
        else {
            for(int i=idx; i<=n; i++) {
                v.push_back(i);
                solve(i+1, n, k-1, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        
        solve(1, n, k, v);
        
        return ans;
    }
};

int main()
{


    return 0;
}