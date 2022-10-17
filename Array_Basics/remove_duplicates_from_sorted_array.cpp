#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currIdx = 0, currElem = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=currElem) {
                currElem = nums[i];
                currIdx++;
                nums[currIdx] = currElem;
            }
        }
        
        return (currIdx+1);
    }
};

int main()
{


    return 0;
}