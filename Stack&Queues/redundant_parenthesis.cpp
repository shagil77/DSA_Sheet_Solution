#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int braces(string A) {
    stack<char> st;
    for(auto ch:A) {
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/') {
            st.push(ch);
        } else if(ch==')') {
            if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/') {
                while(st.top()!='(') st.pop();
                st.pop();
            } else {
                return 1;
            }
        }
    } 
    return 0;
}

int main()
{
    cout<<braces("((a+b)*(c+d))");

    return 0;
}