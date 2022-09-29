#include<bits/stdc++.h>
using namespace std;

class Solution {
    int modulo = 1e9 + 7;
public:
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        unordered_map<char, int> mp;
        vector<int> next(n);
        vector<int> prev(n);
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                prev[i]=mp[s[i]];
            } else {
                prev[i] = -1;
            }
            mp[s[i]] = i;
        }
        
        mp.clear();
        
        for(int i=n-1; i>=0; i--) {
            if(mp.find(s[i]) != mp.end()) {
                next[i]=mp[s[i]];
            } else {
                next[i] = n;
            }
            
            mp[s[i]] = i;
        }
        
        for(int g=0; g<n; g++) {
            for(int i=0, j=g; i<n && j<n; i++, j++) {
                if(g==0) dp[i][j] = 1;
                else if(g==1) dp[i][j] = 2;
                else {
                    if(s[i]==s[j]) {
                        int nxt = next[i];
                        int prv = prev[j];
                        
                        if(nxt > prv) dp[i][j] = ((2 * dp[i + 1][j - 1]) % modulo + 2) % modulo;
                        else if(nxt == prv) dp[i][j] = ((2 * dp[i + 1][j - 1]) % modulo + 1) % modulo;
                        else if(nxt < prv) {
                            // Check for m' length if greater than 1 then only subtract else subtract nothing 1 length subtract nothing(m' does not exist)
                            if (prv - nxt == 1) dp[i][j] = (2 * dp[i + 1][j - 1]) % modulo;
                            else dp[i][j] = ((2 * dp[i + 1][j - 1]) % modulo - dp[nxt + 1][prv - 1] + modulo) % modulo;
                        }
                    } else {
                        dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % modulo - dp[i + 1][j - 1] + modulo) % modulo;
                    }
                }
            }
        }
        
        return dp[0][n-1]%modulo;
    }
};

int main()
{


    return 0;
}