#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

vector<int> prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> G(n);
    for(int i=0; i<A.size(); i++) {
        int j=i-1;
        while(j>=0 && A[j]>=A[i]) j--;
        if(j>=0) G[i]=A[j];
        else G[i]=-1;
    }
    return G;
}

vector<int> prevSmaller2(vector<int> &A) {
    int n=A.size();
    vector<int> g(n);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(i==0) {
            st.push(A[i]);
            g[i]=-1;
        } else {
            while (!st.empty() && st.top()>=A[i]) 
            {
                /* code */
                st.pop();
            }
            if(st.empty()) g[i]=-1;
            else {
                g[i]=st.top();
            }
            st.push(A[i]);
        }
    }
    return g;
}

int main()
{
    vector<int> v={4, 5, 2, 10, 8};
    vector<int> g=prevSmaller2(v);

    for(auto it:g) cout<<it<<" ";
    return 0;
}