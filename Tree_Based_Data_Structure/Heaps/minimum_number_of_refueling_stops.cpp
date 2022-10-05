#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0) {
            if(target>startFuel) return -1;
            return 0;
        }
        
        priority_queue<int> pq;
        int currFuel = startFuel - stations[0][0];
        int countRefuelStops = 0;
        
        if(currFuel<0) return -1;
        
        for(int i=0; i<n; i++) {
            int nextDist;
            if(i==n-1) nextDist = target - stations[i][0];
            else nextDist = stations[i+1][0] - stations[i][0];
            
            pq.push(stations[i][1]);
            currFuel = currFuel - nextDist;
            
            while(!pq.empty() && currFuel<0) {
                int refuel = pq.top();
                pq.pop();
                currFuel = currFuel + refuel;
                countRefuelStops++;
            }
            
            if(currFuel<0) return -1;
        }
        
        return countRefuelStops;
    }
};

int main()
{


    return 0;
}