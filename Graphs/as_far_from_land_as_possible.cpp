#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<pair<int,int>> posOfOnes;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) posOfOnes.push_back({i,j});
            }
        }
        
        if(posOfOnes.size()==0 || posOfOnes.size()==n*n) return -1;
        
        int ans=INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    int minDist=INT_MAX;
                    for(auto it:posOfOnes) {
                        int temp=abs(i-it.first)+abs(j-it.second);
                        minDist=min(minDist, temp);
                    }
                    
                    ans=max(ans,minDist);
                }
            }
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}