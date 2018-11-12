#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
#define Maxsize 10
#define ERROR 0
typedef int ElementType;

//??¡Á¨¦????????
/*typedef struct SNode *Stack;

struct SNode{
    ElementType Data[Maxsize];
    int Top;
};

void push(Stack PtrS,ElementType item)
{
    if (PtrS->Top == Maxsize-1)
    {
        printf("?????¨²");
        return;
    }else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}
ElementType Pop(Stack PtrS)
{
    if(PtrS->Top==-1)
    {
        printf("??????");
        return ERROR;
    }else
        return (PtrS->Data[(PtrS->Top)--]);
}
*/

//??????????????

typedef struct SNode *Stack;

struct SNode{
    ElementType Data;
    struct SNode *Next;
};

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next= NULL;
    return S;
}

int IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

void Push(ElementType item,Stack S)
{
    struct SNode *TmpCell;
    TmpCell = (struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Pop(Stack S)
{
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("??????");
        return NULL;
    }
    else{
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}














