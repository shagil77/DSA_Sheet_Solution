#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *next;
    Node(int v) {
        val=v;
        next=NULL;
    }
};

// struct node
//     {
//         int data;
//         struct node* next;
    
//         node(int x){
//             data = x;
//             next = NULL;
//         }
    
//     }*head;

Node *head=NULL;
int size=0;

// struct node *reverse (struct node *head, int k)
//     { 
//         // Complete this method
//         if(!head) return NULL;
        
//         struct node *curr=head, *prev=NULL, *next=NULL;
//         int count=0;
        
//         while(curr!=NULL && count<k) {
//             next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//             count++;
//         }
        
//         if(next!=NULL) head->next=reverse(next, k);
        
//         return prev;
        
//     }

void insert_back(int val) {
    Node *curr=new Node(val);
    if(head==NULL) {
        head=curr;
        size++;
        return;
    }
    Node *p=head;
    while(p->next) p=p->next;

    p->next=curr;
    size++;
}

void delete_back() {
    if(head==NULL) return;

    Node *p=head;
    while(p->next->next) p=p->next;
    p->next=NULL;
    size--;
}

void reverse_LL() {
    if(head==NULL) return;
    if(head->next==NULL) return;

    Node *prev=NULL;
    Node *curr=head;
    Node *nxt=NULL;

    while(curr!=NULL) {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }

    head=prev;
}

void rotate_LL(int k) {
    Node *p=head;
    Node *cross;
    while(--k) {
        p=p->next;
    }
    
    cross=p;
    while(p->next) {
        p=p->next;
    }
    p->next=head;
    head=cross->next;
    cross->next=NULL;
}

void customDisplay(Node *p) {
    Node *q=p;
    while(q) {
        cout<<q->val<<" ";
        q=q->next;
    }
    cout<<"\n";
}

bool checkLoop() {
    if(head==NULL) return false;
    if(head->next==NULL) return false;

    Node *slow=head;
    Node *fast=head;

    while(slow->next && fast->next->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

void display() {
    Node* p= head;
    while(p) {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main()
{
    head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=head->next->next;

    // insert_back(1);
    // insert_back(2);
    // insert_back(3);
    // insert_back(4);

    

    cout<<checkLoop()<<"\n";

    return 0;
}