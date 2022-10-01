#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxSubArr=INT_MIN;
        int sum = 0;
        mp[0]=0;
        int start=-1, end=-1;
        
        for(int i=0; i<n; i++) {
            sum+=A[i];
            if(mp[sum]==0 && sum!=0) {
                mp[sum] = i+1;
            } else {
                start=mp[sum];
                end=i;
                maxSubArr = max(maxSubArr, end-start+1);
            }
        }
        
        if(maxSubArr==INT_MIN) return 0;
        return maxSubArr;
    }
};

int main()
{


    return 0;
}