#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int solve(string A) {
    stack<char> st;
    for(auto ch:A) {
        if(ch=='(') st.push(ch);
        else if(ch==')'){
            if(st.empty()) return 0;
            else if(st.top()!='(') return 0;
            else st.pop();
        }
    }
    if(st.empty()) return 1;
    return 0;
}

int main()
{
    cout<<solve("(()((((()(");
    

    return 0;
}