#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<vector<int>>> dp;

    int helper(int streak, int i, int j, vector<int>&boxes){
        if(i>j)return 0; 
        if(i==j)return (streak+1)*(streak+1);
        if(dp[i][j][streak]!=-1)return dp[i][j][streak] ;
        int ans = (streak+1)*(streak+1) + helper(0, i+1, j, boxes);
        for(int k = i+1; k<=j ; k++){
            if(boxes[k]==boxes[i]){
                ans = max(ans, helper(0, i+1, k-1, boxes)+helper(streak+1, k, j, boxes)); 
            }
        }
        return dp[i][j][streak] = ans; 
    }
    

public:
    int removeBoxes(vector<int>& boxes) {
        n = boxes.size();
        
        dp = vector<vector<vector<int>>> (n, vector<vector<int>>(n, vector<int>(n+1, -1)));

        return helper(0, 0, n-1, boxes);
    }
};


int main()
{


    return 0;
}