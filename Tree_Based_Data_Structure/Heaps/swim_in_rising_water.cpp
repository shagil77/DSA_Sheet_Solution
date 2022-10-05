#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string,int> mp;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        pq.push({grid[0][0], {0,0}});
        mp["0 0"] = 1;
        
        while(!pq.empty()) {
            int curr = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            
            if(x==n-1 && y==n-1) return curr;
            pq.pop();
            
            for(auto dir:dirs) {
                int xx=x+dir.first, yy=y+dir.second;
                string idx = to_string(xx)+" "+to_string(yy);
                
                if(xx<0 || xx>=n || yy<0 || yy>=n || mp[idx]) continue;
                
                pq.push({max(curr, grid[xx][yy]), {xx,yy}});
                mp[idx] = 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<sol.swimInWater(v);

    return 0;
}