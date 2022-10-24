#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, ListNode*> mp;
        
        ListNode *p = headA;
        while(p!=NULL) {
            mp[p] = p->next;
            p = p->next;
        }
        
        p = headB;
        while(p!=NULL) {
            if(mp.find(p)!=mp.end()) return p;
            p = p->next;
        }
        
        return NULL;
    }
};



int main()
{


    return 0;
}