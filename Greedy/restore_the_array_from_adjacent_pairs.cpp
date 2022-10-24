#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        int n = adjacentPairs.size()+1;
        vector<int> ans(n);
        
        
        for(auto adj: adjacentPairs) {
            mp[adj[0]].push_back(adj[1]);
            mp[adj[1]].push_back(adj[0]);
        }
        
        for(auto p:mp) {
            if(p.second.size()==1) {
                ans[0] = p.first;
                ans[1] = p.second[0];
                break;
            }
        }
        
        int currIdx = 2;
        while(currIdx<n) {
            vector<int> adjElem = mp[ans[currIdx-1]];
            for(auto elem: adjElem) {
                if(elem!=ans[currIdx-2]) ans[currIdx] = elem;
            }
            currIdx++;
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}