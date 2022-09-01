#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        
        right[n-1] = height[n-1];
        for(int j=n-2; j>=0; j--) right[j] = max(height[j], right[j+1]);
        
        left[0] = height[0];
        for(int j=1; j<n; j++) left[j] = max(height[j], left[j-1]);
        
        int ans=0;
        for(int i=1; i<n-1; i++) {
            int trappedRainWater = min(left[i-1], right[i+1]) - height[i];
            if(trappedRainWater>0) ans+=trappedRainWater;
        }
        
        return ans;
    }
};

int main()
{
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(v);

    return 0;
}