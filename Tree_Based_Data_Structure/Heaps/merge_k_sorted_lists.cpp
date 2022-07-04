#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*> &A);
};



ListNode* Solution::mergeKLists(vector<ListNode *> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for (auto linkedList : A)
    {
        ListNode *p = linkedList;

        while(p!=NULL) {
            pq.push(p->val);
            p=p->next;
        }
    }

    ListNode* head=new ListNode(pq.top());
    pq.pop();
    ListNode* p=head;

    while (!pq.empty())
    {
        /* code */
        p->next=new ListNode(pq.top());
        pq.pop();

        p=p->next;
    }
    return head;
}

int main()
{

    return 0;
}