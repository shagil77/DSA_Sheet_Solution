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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr!=NULL) {
            if(curr->val != prev->val) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        
        
        return head;
    }
};

int main()
{


    return 0;
}