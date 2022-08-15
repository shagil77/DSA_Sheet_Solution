#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        int i=0, pow=1;
        
        while(i<=n) {
            if(i==0) {
                dp[i]=0;
                i++;
            }
            else if(i==1) {
                dp[i]=1;
                i++;
            }
            else {
                pow*=2;
                i=pow;
                dp[i]=1;
                i++;
                while(i<2*pow && i<=n) {
                    dp[i]=1+dp[i-pow];
                    i++;
                }
            }
        }
        
        return dp;
    }
};

int main()
{


    return 0;
}