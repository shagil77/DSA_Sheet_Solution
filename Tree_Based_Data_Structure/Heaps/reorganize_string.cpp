#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        if(s.length()==1) return s;
        
        int n=s.length();
        vector<int> count(26, 0);
        vector<char> ans(n);
        int maxCount = INT_MIN;
        char maxChar;
        
        for(auto ch:s) {
            count[ch-'a']++;
            if(count[ch-'a']>maxCount) {
                maxCount=count[ch-'a'];
                maxChar = ch;
            }
        }
        
        if(2*maxCount-1>n) return "";
        int i=0;
        
        while(count[maxChar-'a']) {
            ans[i]=maxChar;
            i+=2;
            count[maxChar-'a']--;
        }
        
        for(int j=0; j<26; j++) {
            while(count[j]) {
                if(i>=n) i=1;
                ans[i]=j+'a';
                i+=2;
                count[j]--;
            }
        }
        
        string res="";
        for(int j=0; j<n; j++) res+=ans[j];
        
        return res;
    }
};

int main()
{


    return 0;
}