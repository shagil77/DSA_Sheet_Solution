#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

long long int max2(long long int a, long long int b) {
    return (a>b)?a:b;
}

long long int maxProduct(const vector<int> &A) {
    int n = A.size();
    long long int mx=INT_MIN;
    
    
    for(int i=0; i<n; i++) {
        long long int f=1;
        for(int j=i; j<n; j++) {
            f*=A[j];
            mx=max(mx, f);
        }
    }
    
    return mx;
}

int main()
{

    vector<int> A={15, 56, 89, 74, -98, -6,56,-8, 6};

    cout<<maxProduct(A);
    return 0;
}