#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    map<int,int> mp;
    struct Node *p1=head1;
    struct Node *p2=head2;
    struct Node *head3=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p3=head3;
    while(p1!=NULL && p2!=NULL) {
        mp[p1->data]++;
        mp[p2->data]++;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=NULL) {
        mp[p1->data]++;
        p1=p1->next;
    }
    while(p2!=NULL) {
        mp[p2->data]++;
        p2=p2->next;
    }
    
    int l=mp.size();
    for(auto p:mp) {
        p3->data=p.first;
        l--;
        if(l==0) p3->next=NULL;
        else {
            p3->next=(struct Node*) malloc(sizeof(struct Node));
            p3=p3->next;
        }
    }
    return head3;
    
}


int main()
{


    return 0;
}