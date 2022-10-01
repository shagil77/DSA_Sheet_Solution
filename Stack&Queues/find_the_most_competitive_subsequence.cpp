#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k) return nums;
        
        vector<int> ans(k);
        stack<int> st;
        
        for(int currIdx=0; currIdx<n; currIdx++) {
            while(!st.empty() && st.top()>nums[currIdx] && (n-(k-st.size())-1)>=currIdx)
                st.pop();
            if(st.size()<k) st.push(nums[currIdx]);
        }
        
        int i=k-1;
        while(!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i--;
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}