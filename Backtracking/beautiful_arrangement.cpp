#include<bits/stdc++.h>
using namespace std;

class Solution {
    int count;
    int N;
    
    void solve(int pos, unordered_map<int,int>& mp) {
        if(pos==N+1) {
            count++;
            return;
        }
        
        for(int i=1; i<=N; i++) {
            if(mp[i]==1) continue;
            if(i%pos!=0 && pos%i!=0) continue;
            
            mp[i]=1;
            
            solve(pos+1, mp);
            
            mp[i]=0;
        }
    }
public:
    int countArrangement(int n) {
        count = 0;
        N = n;
        unordered_map<int, int> mp;
        
        solve(1, mp);
        
        return count;
    }
};

int main()
{


    return 0;
}