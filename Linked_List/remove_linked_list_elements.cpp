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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(curr->next == NULL && curr->val==val) return NULL; 
        
        while(curr!=NULL) {
            if(curr->val == val) {
                if(prev!=NULL) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        
        return head;
    }
};

int main()
{


    return 0;
}