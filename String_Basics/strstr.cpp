#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int strStr(const string A, const string B) {
    int n=A.length(), m=B.length();
    if(n==0 || m==0) return -1;
    if(n==m) {
        int k;
        for(k=0; k<n; k++) {
            if(A[k]!=B[k]) return -1;
        }
        if(k==n) return 0;
    }
    int i=0, j=m-1;
    while(i<=n-m) {
        int l=0,k;
        for(k=i; k<=j; k++) {
            if(A[k]==B[l]) l++;
            else {
                i++;
                j++;
                break;
            }
        }
        if(l==m) return i;
    }
    return -1;
}


int main()
{

    cout<<strStr("shagilislam", "isl");
    return 0;
}