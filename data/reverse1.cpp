#include <bits/stdc++.h>

using namespace std;

typedef struct ListNode *Node;
struct ListNode {
    int val;
    struct ListNode *next;
};


void Insert(Node *head)
{
    Node P;
    int i=3;
    P = (Node)malloc(sizeof(struct ListNode));
    P->val = i;

    (*head)->next = P;
    *head = P;
}

Node Readnode(int n)
{
    Node P,t,rear;
    P = (Node)malloc(sizeof(struct ListNode));
    P->next = NULL;
    rear = P;

    while(n--)
    {   
        Node q;
        q = (Node)malloc(sizeof(struct ListNode));
        q->val = n;
        q->next = NULL;
        rear->next = q;
        rear = q;
    }

    t = P;
    P = P->next;
    free(t);
    return P;
}


void Print(Node P)
{
    int flag = 1;
    while(P)
    {
        if(flag)
            flag = 0;
        else
            cout<<"->";
        cout<<P->val;
        P = P->next;
    }
}

struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL)
            return head;
    struct ListNode* newH;
    struct ListNode* cur;
    struct ListNode* pre;
    struct ListNode* suc;

    pre = head;
    cur = head->next;
    newH = (struct ListNode*)malloc(sizeof(struct ListNode));
    newH->next = head;
    head->next = NULL;
    
    while(cur!=NULL)
    {
        suc = cur->next; 
        cur->next = newH->next;
        newH->next = cur;

        cur = suc;
    }

    return newH->next;
}
/*struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* P;
    struct ListNode* t;
    struct ListNode* cur;
    P = (struct ListNode*)malloc(sizeof(struct ListNode));
    P->next = NULL;
    cur = P;

    while(l1&&l2){
    if(l1->val==l2->val)
    {
        cur->next = l1;
        l1 = l1->next;
        l2 = l2->next;
        cur = cur->next;
    }
    else if(l1->val<l2->val)
    {
        cur->next = l1;
        l1 = l1->next;
        cur = cur->next;
    }
    else if(l1->val>l2->val)
    {
        cur->next = l2;
        l2 = l2->next;
        cur = cur->next;
    }
    }
    while(l1)
    {
        cur->next = l1;
        l1 = l1->next;
        cur = cur->next;
    }
    while(l2)
    {
        cur->next = l2;
        l2 = l2->next;
        cur = cur->next;
    }
    t = P;
    P = P->next;
    free(t);
    return P;
}*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* P;
    struct ListNode* cur;
    P = (struct ListNode*)malloc(sizeof(struct ListNode));
    P->next = NULL;
    cur = P;
    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1?l1:l2;
    return P->next;
}

Node DeleteRange(Node N,int max,int min)
{
    Node t;
    Node cur;
    Node pre;
    pre = (Node)malloc(sizeof(struct ListNode));
    pre->next = N;
    cur = N;
    while(cur)
    {
        if(cur->val>=min&&cur->val<=max)
        {
            t = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(t);
        }else{
            cur = cur->next;
            pre = pre->next;
        }
            
    }
    return N;
}


int main()
{
    Node head;
    Node head1;
    Node h,a,a1,a2,a3;
    head = Readnode(3);
    a = Readnode(6);
    a3 = Readnode(6);
    a3 = reverseList(a3);
    head1 = reverseList(head);
    a1 = reverseList(a);
    //h = mergeTwoLists(a1,head1);
    a2 = DeleteRange(a1,4,1);
    Print(a3);
    cout<<endl;
    Print(a2);
    cout<<endl;
    //Print(h);
    return 0;
}


