#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        queue<int> t=q1;
        q1=q2;
        q2=t;
        return ans;
    }
    
    int top() {
        if(q1.empty()) return -1;
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        q2.push(ans);
        queue<int> t=q1;
        q1=q2;
        q2=t;
        return ans;
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *st=new MyStack();
    st->push(1);
    st->push(2);
    st->push(3);

    cout<<st->top()<<"\n";
    st->pop();
    st->push(4);
    cout<<st->top()<<"\n";
    
    return 0;
}