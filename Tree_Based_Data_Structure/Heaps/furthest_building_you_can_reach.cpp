#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int b = bricks, l = ladders, i;
        for(i=0; i<n-1; i++) {
            if(heights[i]>=heights[i+1]) continue;
            
            int gap = heights[i+1]-heights[i];
            b -= gap;
            pq.push(gap);
            
            if(b<0) {
                b += pq.top();
                pq.pop();
                l--;
            }
            
            if(l<0) break;
        }
        
        return i;
    }
};

int main()
{


    return 0;
}