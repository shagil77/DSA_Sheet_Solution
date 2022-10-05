#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int i=0, j=0;
        deque<int> dq;
        
        while(j<n) {
            while(!dq.empty() && dq.back()<nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
            
            if(j-i+1<k) j++;
            else if(j-i+1==k) {
                ans.push_back(dq.front());
                if(nums[i]==dq.front()) dq.pop_front();
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> inp = {1,3,-1,-3,5,3,6,7}; // 1,3,-1,-3,5,3,6,7
    vector<int> ans = sol.maxSlidingWindow(inp, 3);

    for(auto it: ans) cout<<it<<" ";

    return 0;
}