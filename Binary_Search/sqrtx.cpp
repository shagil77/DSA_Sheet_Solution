#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int s=1, e=x;
        while(s<e) {
            long long int m=s+(e-s)/2;
            long long int ms=m*m-x;
            if(ms>0) e=m;
            else s=m;
            
            int t=s+(e-s)/2;
            if(t==m) break;
        }
        return s;
    }
};

int main()
{


    return 0;
}