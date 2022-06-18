#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int min(int a, int b) {
    return (a<b)?a:b;
}

string longestCommonPrefix(vector<string> &A) {
    int l=INT_MAX, idx=0;
    if(A.size()==1) return A[0];
    for(auto s:A) l=min(l,s.length());
    
    for(int i=0; i<l; i++) {
        char elem=A[0][i];
        for(int j=1; j<A.size(); j++) {
            if(A[j][i]!=elem) {
                return A[0].substr(0, i);
            }
        }
    }
    
    return A[0].substr(0, l);
}



int main()
{
    vector<string> A = {"shagil", "sruti", "trisha"};
    cout<<longestCommonPrefix(A);

    return 0;
}