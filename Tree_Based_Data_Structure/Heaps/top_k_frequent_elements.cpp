#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> v;
        
        for(auto num:nums) mp[num]++;
        
        for(auto p:mp) pq.push({p.second, p.first});
        
        for(int i=0; i<k; i++) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};

int main()
{


    return 0;
}