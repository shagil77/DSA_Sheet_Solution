#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

static int solveUtil(vector<int> &A, int l, int r) {
    if(r-l+1==1) return 1;
    int root=A[l];
    int m=l;
    for(int i=l+1; i<=r; i++) {
        if(A[i]==root) return 0;
        if(A[i]>root) {
            m=i;
            break;
        }
        
    }
    if(m==l) return 1;
    
    for(int right=m+1; right<=r; right++) {
        if(A[right]<root) return 0;
    }
    return (solveUtil(A, l+1, m-1) && solveUtil(A, m, r));
}

int solve(vector<int> &A) {
    int l=0, r=A.size()-1;
    return solveUtil(A, l, r);
}


int main()
{


    return 0;
}