#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int firstUniqChar(string s) {
        int n=s.length();
        // 97 to 122
        int mp[26]={0};
        queue<pair<char, int>> q;
        
        for(int i=0; i<n; i++) {
            int ch=s[i]-97;
            if(mp[ch]==0) {
                q.push(make_pair(s[i], i));
            }
            mp[ch]++;
        }
        
        while(!q.empty()) {
            int ch=q.front().first-97;
            if(mp[ch]==1) return q.front().second;
            q.pop();
        }
        return -1;
    }

int main()
{


    return 0;
}