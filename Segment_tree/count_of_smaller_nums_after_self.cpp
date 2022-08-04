#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> seg; // min, max
    vector<int> count;
    
    void updateTree(int index, int low, int high, int val) {
        
        if(low<=val && val<=high) {
            seg[index]++;
            if(low==high) return;

            int mid = floor((low+high)/2.0);

            if(val<=mid) updateTree(2*index+1, low, mid, val);
            else updateTree(2*index+2,mid+1,high,val);
        }
        
    }
    
    int calcCount(int index, int low, int high, int l, int r) {

        // if(l>r) return 0;

        // int m=(low+high)/2;
        // if(l<=m && m<=r) return seg[index];

        // if(m<l) return calcCount(2*index+2,m+1,high,l,r);

        // return calcCount(2*index+1,low,m,l,r);
        if(low>=l && high<=r) return seg[index];
        if(high<l || low>r) return 0;

        int m = floor((low+high)/2.0);
        int left = calcCount(2*index+1,low,m,l,r);
        int right = calcCount(2*index+2,m+1,high,l,r);

        return (left+right);

    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        count.resize(n);
        int low = *min_element(nums.begin(), nums.end()), high = *max_element(nums.begin(), nums.end());
        seg.resize(4*(high-low+1));

        for(int i=n-1; i>=0; i--) {
            count[i]=calcCount(0,low,high,low,nums[i]-1);

            updateTree(0,low,high,nums[i]);
        }
        
        return count;
    }
};


int main()
{
    vector<int> nums={26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    Solution s;
    vector<int> ans = s.countSmaller(nums);

    for(auto it:ans) cout<<it<<" ";
    // cout<<ans.size();
    

    return 0;
}