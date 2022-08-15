#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int res=*max_element(nums.begin(), nums.end());
        int currMin=1, currMax=1;
        
        for(auto num:nums) {
            if(num==0) {
                currMin=currMax=1;
                continue;
            } 
            
            int maxi=max(num, max(num*currMax, num*currMin));
            int mini=min(num, min(num*currMax, num*currMin));
            
            currMax=maxi;
            currMin=mini;
            
            res=max(currMax,res);
        }
        
        return res;
    }
};

int main()
{
    return 0;
}