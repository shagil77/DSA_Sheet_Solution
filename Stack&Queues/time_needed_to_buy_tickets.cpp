#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int time=0;
        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(i);
        }
        
        while(true) {
            int index=q.front();
            q.pop();
            tickets[index]--;
            time++;
            if(tickets[index]==0 && index==k) return time;
            if(tickets[index]!=0) q.push(index);
        }
        return -1;
    }
};

int main()
{


    return 0;
}