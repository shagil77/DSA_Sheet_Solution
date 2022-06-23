#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} * head;

struct node *reverse(struct node *head, int k)
{
    // Complete this method
    if (!head)
        return NULL;

    struct node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (head!=NULL)
        head->next=curr;

    count=0;

    while(curr!=NULL && count<k-1) {
        curr=curr->next;
        count++;
    }

    if (curr != NULL) {
        curr->next = reverse(curr->next, k);
    }
        
    return prev;
}
int main()
{


    return 0;
}