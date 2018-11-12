#include<bits/stdc++.h>
#define EORRE -1
using namespace std;


typedef int ElementType;
typedef struct SNode *Stack;

struct SNode{
    ElementType x;
    ElementType y;
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

void Push(ElementType x,ElementType y,Stack S)
{
    Stack Tmp;
    Tmp = (Stack)malloc(sizeof(struct SNode));
    Tmp->x = x;
    Tmp->y = y;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}

Stack Pop(Stack S)
{
    Stack FirstCell;
    Stack top;
    if(IsEmpty(S))
    {
        cout<<"栈为空";
        return NULL;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        top = (Stack)malloc(sizeof(struct SNode));
        top->x = FirstCell->x;
        top->y = FirstCell->y;
        top->Next = NULL;
        free(FirstCell);
        return top;
    }
}

// void show(Stack S){
//     Stack temp;
//     if(S->Next != NULL){
//         temp = Pop(S);
//         show(S);
//         cout << "(" << temp->x << "," << temp->y << ")" << endl;
//     }
// }


void show(Stack S)
{
    Stack tmp;
    Stack r;
    Stack t;
    tmp = CreatStack();
    while(!IsEmpty(S))
    {
        r = Pop(S);
        Push(r->x,r->y,tmp);
    }
    while(!IsEmpty(tmp))
    {
        t = Pop(tmp);
        Push(t->x,t->y,S);
        cout << "(" << t->x << "," << t->y << ")" << endl;
    }
}
int main()
{
    Stack S;
    S = CreatStack();
    Push(1,2,S);
    Push(3,4,S);
    Push(5,6,S);
    show(S);
    return 0;
}





