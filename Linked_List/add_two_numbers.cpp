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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = NULL;
        ListNode *list = NULL;
        bool flag = false;
        int carry = 0;
        
        list = new ListNode((carry + p1->val + p2->val)%10);
        head = list;
        carry = (carry + p1->val + p2->val)/10;
        p1 = p1->next;
        p2 = p2->next;
        
        while(p1!=NULL && p2!=NULL) {
            int num = carry + p1->val + p2->val;
            carry = num/10;
            num = num%10;
            list->next = new ListNode(num);
            
            list = list->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1!=NULL) {
            int num = carry + p1->val;
            carry = num/10;
            num = num%10;
            list->next = new ListNode(num);
            
            list = list->next;
            p1 = p1->next;
        }
        
        while(p2!=NULL) {
            int num = carry + p2->val;
            carry = num/10;
            num = num%10;
            list->next = new ListNode(num);
            
            list = list->next;
            p2 = p2->next;
        }
        
        if(carry!=0) list->next = new ListNode(carry);
        
        return head;
    }
};

int main()
{


    return 0;
}