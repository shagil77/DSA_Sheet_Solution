#include<bits/stdc++.h>
using namespace std;

class Solution {
    int sumOfSquares(int n) {
        int copy = n, sum = 0;
        while(copy!=0) {
            sum += (copy%10)*(copy%10);
            copy /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if(n==1) return true;
        
        int num = n;
        unordered_map<int, int> mp;
        
        while(true) {
            int newNum = sumOfSquares(num);
            if(newNum==1) return true;
            if(mp[newNum]==1) return false;
            num = newNum;
            mp[num] = 1;
        }
        
        return false;
    }
};

int main()
{


    return 0;
}