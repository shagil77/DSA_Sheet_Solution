#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0], ans=INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            ans=max(ans, prices[i]-mn);
            mn=min(mn, prices[i]);
        }
        
        return ((ans<0)?0:ans);
    }
};

int main()
{


    return 0;
}