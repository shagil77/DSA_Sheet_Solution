#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int surplusGas = 0, currGas = 0, start = 0;
        
        for(int i=0; i<n; i++) {
            surplusGas += gas[i]-cost[i];
            currGas += gas[i]-cost[i];
            if(currGas<0) {
                currGas = 0;
                start = i+1;
            }
        }
        
        if(surplusGas<0) return -1;
        return start;
    }
};

int main()
{


    return 0;
}