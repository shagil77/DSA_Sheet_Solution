#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string removeKdigits(string num, int k) {
        string ans = ""; // using a string as a stack
        
        for(auto ch:num) {
            while(ans.size() && ans.back()>ch && k) {
                ans.pop_back();
                k--;
            }
            if(ans.size() || ch!='0') ans.push_back(ch);
        }
        
        while(ans.size() && k) {
            ans.pop_back();
            k--;
        }
        
        return (ans=="")?"0":ans;
    }
};

int main()
{


    return 0;
}