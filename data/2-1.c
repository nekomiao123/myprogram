#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    
}
void Print(List L)
{
    if(!L)
    {
        printf("NULL");
    }
}

List Merge(List L1,List L2)
{
    List L,tmp1,tmp2;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List tmp;
    tmp = L;
    tmp1 = L1->Next;
    tmp2 = L2->Next;
    while(tmp1&&tmp2)
    {
        if(tmp1->Data<=tmp2->Data)
        {
            tmp->Next = tmp1;
            tmp1 = tmp1->Next;
            tmp = tmp->Next;
        }else
        {
            tmp->Next = tmp2;
            tmp2 = tmp2->Next;
            tmp = tmp->Next;
        }
    }
    while(tmp1)
    {
        tmp->Next = tmp1;
        tmp1 = tmp1->Next;
        tmp = tmp->Next;
    }
    while(tmp2)
    {
        tmp->Next = tmp2;
        tmp2 = tmp2->Next;
        tmp = tmp->Next;
    }
    L1->Next=NULL;  
    L2->Next=NULL;
    tmp->Next=NULL;

    return L;
}