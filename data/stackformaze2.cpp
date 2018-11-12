#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int x;    //横坐标
    int y;    //纵坐标
    struct LNode *next;
}LNode;

typedef struct {
    LNode *top; //栈的顶部
}Stack;

void IntiStack(Stack *S){

    S->top = (LNode *)malloc(sizeof(LNode));
    S->top->next = NULL;
}

bool IsEmpty(Stack *S)
{
    return (S->top->next==NULL);
}

void Push(Stack *S, int x, int y){
    LNode *topNode = (LNode *)malloc(sizeof(LNode));
    topNode->x = x;
    topNode->y = y;
    topNode->next = S->top->next;
    S->top->next = topNode;
}

LNode *Pop(Stack *S){
    LNode *temp = S->top->next;
    if(temp != NULL){
        S->top->next = temp->next;
    }
    temp->next = NULL;
    return temp;
}

void show(Stack *S){
    LNode *temp;
    if(S->top->next != NULL){
        temp = Pop(S);
        show(S);
        cout << "(" << temp->x << "," << temp->y << ")" << endl;
    }
}

int main()
{
    Stack S;
    IntiStack(&S);
    Push(&S,1,2);
    Push(&S,3,4);
    show(&S);
    return 0;
}