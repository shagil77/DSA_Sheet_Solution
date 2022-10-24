#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> charMap;
        unordered_map<int, int> freqMap;
        priority_queue<pair<int, int>> pq;
        
        for(auto ch:s) charMap[ch]++;
        
        for(auto mp:charMap) freqMap[mp.second]++;
        
        for(auto mp:freqMap) pq.push({mp.first, mp.second});
        
        int curr = pq.top().first;
        int cost = 0;
        while(!pq.empty()) {
            int charFreq = pq.top().first, charFreqFreq = pq.top().second;
            pq.pop();
            curr = min(curr, charFreq);
            // cout<<curr<<" "<<cost<<"\n";
            
            while(charFreqFreq>1) {
                if(curr==0) {
                    cost += charFreq*(charFreqFreq-1);
                    break;
                } 
                
                while(freqMap[curr]!=0 && curr>0) curr--;
                
                if(curr==0) {
                    cost += charFreq*(charFreqFreq-1);
                    break;
                }
                
                if(freqMap[curr]==0) {
                    cost += (charFreq-curr);
                    freqMap[curr]++;
                }
                charFreqFreq--;
            }
        }
        
        return cost;
    }
};

int main()
{
    Solution sol;
    cout<<sol.minDeletions("accdcdadddbaadbc")<<"\n";

    return 0;
}