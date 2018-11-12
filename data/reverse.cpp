#include <bits/stdc++.h>

using namespace std;



struct ListNode {
     int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
            return head;
    struct ListNode* pre;
    struct ListNode* cur;
    struct ListNode* suc;

    pre = NULL;
    cur = head;
    suc = cur;
   
    while(cur)
    {   
        suc = suc->next;
        cur->next = pre;
        pre = cur;
        cur = suc;
    }
    return head;
}


int main()
{
    return 0;
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
    cur = pre->next;
    newH = (struct ListNode*)malloc(sizeof(struct ListNode));
    newH->next = pre;
    head->next = NULL;
    
    while(cur)
    {
        suc = cur->next;
        cur->next = newH->next;
        newH->next = cur;
        cur = suc;
    }

    return newH->next;
}



struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL)
            return head;
    struct ListNode* newH;
    struct ListNode* cur;
    struct ListNode* suc;

    newH = NULL;
    cur = head;

    while(cur)
    {
        suc = cur->next;
        cur->next = newH;
        newH = cur;
        cur = suc;
    }

    return newH;
}



