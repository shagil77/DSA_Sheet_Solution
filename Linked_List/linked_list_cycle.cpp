#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *hare = head;
        ListNode *tortoise = head;

        while (hare != NULL && tortoise->next != NULL)
        {
            hare = hare->next;
            tortoise = tortoise->next->next;

            if (tortoise == NULL)
                return false;
            if (hare == tortoise)
                return true;
        }

        return false;
    }
};

int main()
{

    return 0;
}