#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//     int climbStairs(int n) {
//         if(n==0) return 1;
        
//         int left=0, right=0;
        
//         if(n-1>=0) left=climbStairs(n-1);
//         if(n-2>=0) right=climbStairs(n-2);
        
//         return (left+right);
//     }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=n; i++) {
            int left=((i-1)>=0)?dp[i-1]:0;
            int right=((i-2)>=0)?dp[i-2]:0;
            
            dp[i]=left+right;
        }
        
        return dp[n];
    }
};

int main()
{


    return 0;
}