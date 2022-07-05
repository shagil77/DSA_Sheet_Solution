#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

long long int nthFibonacci(long long int n){
        // code here
        long long int m=1000000007;
        long long int DP[n+1];
        DP[0]=0;
        DP[1]=1;
        for(int i=2; i<=n; i++) {
            DP[i]=(DP[i-1]+DP[i-2])%m;
        }
        return DP[n]%m;
    }

int main()
{


    return 0;
}