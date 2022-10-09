#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Method 1: Using nth_element
    // Method 2: Using partial_sort
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};

int main()
{


    return 0;
}