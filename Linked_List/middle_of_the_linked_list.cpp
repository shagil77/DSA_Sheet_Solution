#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == NULL)
            return head;

        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;

            if (p2 == NULL)
                break;
        }

        return p1;
    }
};

int main()
{

    return 0;
}