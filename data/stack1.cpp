#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
#define Maxsize 10
#define ERROR 0
#define EmptyTOS -1
using namespace std;
typedef int ElementType;

typedef struct StackRecord *Stack;
struct StackRecord
{
    int Capacity;
    int TopOfstack;
    ElementType *Array;
};

Stack CreateStack()
{
    Stack S;

    S = (Stack)malloc(sizeof(struct StackRecord));
    if(S==NULL)
    {
        cout<<"Out of space";
    }
    S->Array = (ElementType*)malloc(sizeof(ElementType)*Maxsize);
    if(S->Array==NULL)
        cout<<"Out of space";
    S->Capacity = Maxsize;

    return S;
}


int IsEmpty(Stack S)
{
    return S->TopOfstack == EmptyTOS;
}

void MakeEmpty(Stack S)
{
    S->TopOfstack = EmptyTOS;
}

void Push(ElementType X,Stack S)
{
    if(S->TopOfstack == Maxsize-1)
    return;
    else{
        S->Array[++S->TopOfstack] = X;
    }
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        cout<<"Out of space";
    else 
        S->TopOfstack--;
}
