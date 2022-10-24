#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode *list = new ListNode();
        ListNode *head = list;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        
        if(p1->val<p2->val) {
            list = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            list = new ListNode(p2->val);
            p2 = p2->next;
        }
        
        head = list;
        
        while(p1!=NULL && p2!=NULL) {
            if(p1->val<p2->val) {
                list->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                list->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            list = list->next;
        }
        
        while(p1!=NULL) {
            list->next = new ListNode(p1->val);
            p1 = p1->next;
            list = list->next;
        }
        
        while(p2!=NULL) {
            list->next = new ListNode(p2->val);
            p2 = p2->next;
            list = list->next;
        }
        
        return head;
    }
};



int main()
{


    return 0;
}