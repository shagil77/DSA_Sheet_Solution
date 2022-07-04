#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

vector<int> solve(vector<int> &A, int B) {
    vector<int> ans;
    priority_queue<int> pq;
    
    for(auto it:A) pq.push(it);
    
    for(int i=0; i<B; i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{


    return 0;
}