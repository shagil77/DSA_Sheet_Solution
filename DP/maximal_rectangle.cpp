#include<bits/stdc++.h>
using namespace std;

class Solution {
    int largestRectangleArea(vector<int> &A) {
    int n=A.size();
    stack<pair<int,int>> st;
    vector<pair<int,int>> nsl(n); //{elem, index}
    vector<pair<int,int>> nsr(n);
    for(int i=0; i<n; i++) {
        if(i==0) {
            st.push(make_pair(A[i], i));
            nsl[i]=make_pair(-1,-1);
        } else {
            while(!st.empty() && st.top().first>=A[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nsl[i]=make_pair(-1, -1);
            }
            else {
                nsl[i]=st.top();
            }
            st.push(make_pair(A[i], i));
        }
    }
    while(!st.empty()) st.pop();

    for(int i=n-1; i>=0; i--) {
        if(i==n-1) {
            st.push(make_pair(A[i], i));
            nsr[i]=make_pair(n,n);
        } else {
            while(!st.empty() && st.top().first>=A[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nsr[i]=make_pair(n,n);

            }
            else {
                nsr[i]=st.top();
            }
            st.push(make_pair(A[i], i));
        }
    }
    int ans=INT_MIN;

    for(int i=0; i<n; i++) {
        int H=A[i];
        int L=nsl[i].second, R=nsr[i].second;

        ans=max(ans, (R-L-1)*H);
    }
    return ans;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n,0));
        int res = 0;
        
        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                if(i==0) {
                    height[i][j] = matrix[i][j]-'0';
                } else {
                    height[i][j] = (matrix[i][j]=='0')?0:(height[i-1][j] + 1);
                }
            }
        }
        
        for(int i=0; i<m; i++) res = max(res, largestRectangleArea(height[i]));
        
        return res;
    }
};

int main()
{


    return 0;
}