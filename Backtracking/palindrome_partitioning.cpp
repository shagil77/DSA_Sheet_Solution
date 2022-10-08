#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    int N;
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void solve(int idx, string s, vector<string>& v) {
        if(idx==N) {
            ans.push_back(v);
            return;
        }
        
        for(int i=idx; i<N; i++) {
            if(isPalindrome(s, idx, i)) {
                v.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        N = s.length();
        vector<string> v;
        
        solve(0, s, v);
        
        return ans;
    }
};

int main()
{


    return 0;
}