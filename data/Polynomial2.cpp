#include <bits/stdc++.h>
using namespace std;



struct ListNode {
   int val;
   struct ListNode *next;
};

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