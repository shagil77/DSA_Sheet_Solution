#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long int catalanNumber(int n) {
        if(n==0) return 1;

        long long int ans = ((4*n-2)*catalanNumber(n-1))/(n+1);

        return ans;
    }

    // Brute Force
    // int solve(int l, int r) {
    //     if(l>=r) return 1;

    //     int sum=0;

    //     for(int i=l; i<=r; i++) {
    //         int left = solve(l, i-1);
    //         int right = solve(i+1, r);

    //         sum+=(left*right);
    //     }

    //     return sum;
    // }
public:
    int numTrees(int n) {
        return catalanNumber(n);
    }
};

int main()
{


    return 0;
}