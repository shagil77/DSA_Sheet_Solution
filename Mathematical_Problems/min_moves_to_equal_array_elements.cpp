#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, minNum = INT_MAX;
        
        for(auto num:nums) {
            sum += num;
            minNum = min(minNum, num);
        }
        
        int ans = sum - minNum*n;
        return ans;
    }
};

int main()
{


    return 0;
}