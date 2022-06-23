#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

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

    // for(int i=0; i<n; i++) {
    //     cout<<nsl[i].second<<" "<<nsr[i].second<<"\n";
    // }

    for(int i=0; i<n; i++) {
        int H=A[i];
        int L=nsl[i].second, R=nsr[i].second;

        ans=max(ans, (R-L-1)*H);
    }
    return ans;
}

int main()
{
    vector<int> v={47, 69, 67, 97, 86, 34, 98, 16, 65, 95, 66, 69, 18, 1, 99, 56, 35, 9, 48, 72, 49, 47, 1, 72, 87, 52, 13, 23, 95, 55, 21, 92, 36, 88, 48, 39, 84, 16, 15, 65, 7, 58, 2, 21, 54, 2, 71, 92, 96, 100, 28, 31, 24, 10, 94, 5, 81, 80, 43, 35, 67, 33, 39, 81, 69, 12, 66, 87, 86, 11, 49, 94, 38, 44, 72, 44, 18, 97, 23, 11, 30, 72, 51, 61, 56, 41, 30, 71, 12, 44, 81, 43, 43, 27};
    cout<<largestRectangleArea(v)<<"\n";
    return 0;
}