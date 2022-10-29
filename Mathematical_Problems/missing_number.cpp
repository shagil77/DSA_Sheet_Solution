#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int req_sum = (n*(n+1))/2;
        
        return (req_sum-sum);
    }
};

int main()
{


    return 0;
}