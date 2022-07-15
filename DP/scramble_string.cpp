#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

static unordered_map<string,int> mp;

int isScramble(const string A, const string B) {
    if(A.length()!=B.length()) return false;
    if(A==B) return true;
    
    string key=A+" "+B;
    int n=A.length();
    if(mp[key]!=0) return ((mp[key]==1)?true:false);
    
    for(int k=1;k<n;k++) {
        bool c1=isScramble(A.substr(0,k),B.substr(0,k)) && isScramble(A.substr(k),B.substr(k));
        bool c2=isScramble(A.substr(0,k),B.substr(n-k)) && isScramble(A.substr(k), B.substr(0,n-k));
        
        if(c1 || c2) {
            mp[key]=1;
            return 1;
        }
    }
        
    mp[key]=2;
    return false;
}

int main()
{


    return 0;
}