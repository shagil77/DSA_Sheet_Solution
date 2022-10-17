#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    int lengthOfList(ListNode* head) {
        if(head==NULL) return 0;
        ListNode* curr = head;
        
        int n=1;
        while(curr->next!=NULL) {
            n++;
            curr = curr->next;
        }
        
        return n;
    }
public:
    int getDecimalValue(ListNode* head) {
        int n = lengthOfList(head);
        ListNode* p = head;
        
        long long int sum = 0;
        while(n>0) {
            sum += (p->val)*pow(2,n-1);
            p = p->next;
            n--;
        }
        
        return sum;
    }
};

int main()
{


    return 0;
}