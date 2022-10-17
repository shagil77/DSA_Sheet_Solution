#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int oneCount=0, twoCount=0, zeroCount=0;
        for(auto num:nums) {
            if(num==0) zeroCount++;
            else if(num==1) oneCount++;
            else twoCount++;
        }
        
        for(int i=0; i<zeroCount; i++) nums[i]=0;
        for(int i=zeroCount; i<zeroCount+oneCount; i++) nums[i]=1;
        for(int i=zeroCount+oneCount; i<zeroCount+oneCount+twoCount; i++) nums[i]=2;
        
    }
};


int main()
{


    return 0;
}