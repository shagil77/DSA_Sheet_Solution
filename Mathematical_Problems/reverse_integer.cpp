#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN || x==INT_MAX) return 0;

        string maxInt = "2147483647";
        string minInt = "-2147483648";
        string curr = "";
        
        int copy = x, rev = 0, i=0;
        bool canReverse = false;

        if(x<0) {
            curr = minInt;
            i=1;
            copy = copy*(-1);
        } else {
            curr = maxInt;
            i=0;
        }
        
        if(to_string(x).length()>curr.length()) return 0;
        if(to_string(x).length()<curr.length()) canReverse = true;
        
        while(copy!=0) {
            int num = copy%10;
            
            if(!canReverse) {
                cout<<num<<" "<<(curr[i]-'0')<<"\n";
                if(num<(curr[i]-'0')) canReverse = true;
                else if(num==(curr[i]-'0')) i++;
                else return 0;
            }
            
            rev = rev*10 + num;
            copy/=10;
        }

        if(x<0) rev = rev*(-1);
        
        return rev;
    }
};

// Value of INT_MAX is +2147483647.
// Value of INT_MIN is -2147483648.

int main()
{
    Solution sol;
    cout<<sol.reverse(-2147483648);
    // 964632435

    return 0;
}