#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        
        
        double power = log2(n);
        int copy = power;
        
        return (copy==power);
    }
};

int main()
{


    return 0;
}