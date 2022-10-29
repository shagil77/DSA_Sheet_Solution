#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return (n-1);
        
        int l = 1, h = n-2, m;
        int ans = -1;
        
        
        while(l<=h) {
            m = l+(h-l)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]) break;
            else if(nums[m]<nums[m+1]) l = m+1;
            else h = m-1;
        }
        
        return m;
    }
};

int main()
{


    return 0;
}