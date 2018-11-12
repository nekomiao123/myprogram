#include<bits/stdc++.h>
#define EORRE -1
using namespace std;


typedef char ElementType;
typedef struct SNode *Stack;

struct SNode{
    ElementType Data;
    struct SNode *Next;
};


Stack CreatStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

void Push(ElementType item,Stack S)
{
    Stack Tmp;
    Tmp = (Stack)malloc(sizeof(struct SNode));
    Tmp->Data = item;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}

ElementType Pop(Stack S)
{
    Stack FirstCell;
    ElementType top;
    if(IsEmpty(S))
    {
        cout<<"Õ»Îª¿Õ";
        return EORRE;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        top = FirstCell->Data;
        free(FirstCell);
        return top;
    }

}

void input(Stack S)
{
    ElementType a;
    while (cin>>a)
    {
        Push(a,S);
    }
}

void output(Stack S)
{
    ElementType b;
    while(!IsEmpty(S))
    {
        b = Pop(S);
        cout<<b<<" ";
    }
    cout<<endl;
}

int main()
{
    Stack S;
    S = CreatStack();
    input(S);
    output(S);

    return 0;
}