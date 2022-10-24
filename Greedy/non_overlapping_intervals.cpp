#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort the intervals based on starting point (or ending point)
        sort(intervals.begin(), intervals.end());
        
        int ans = -1;
        int prevEnd = intervals[0][1];
        
        for(auto interval:intervals) {
            if(interval[0]<prevEnd) {
                ans++;
                prevEnd = min(prevEnd, interval[1]);
            } else 
                prevEnd = interval[1];
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}