#include <bits/stdc++.h>
#define ERROR 0
typedef int ElementType;
typedef int Position;
//数组储存
/*typedef struct QNode *Queue;
struct QNode{
    ElementType *Data;
    Position Fornt,Rear;
    int MaxSize;
};
Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Fornt = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
bool IsFull(Queue Q)
{
    return((Q->Rear+1)%Q->MaxSize==Q->Fornt);
}

bool AddQ(Queue Q,ElementType X)
{
    if(IsFull(Q)){
        printf("队列满");
        return false;
    }
    else{
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Fornt==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q)){
        printf("队列空");
        return ERROR;
    }
    else{
        Q->Fornt = (Q->Fornt+1)%Q->MaxSize;
        return Q->Data[Q->Fornt];
    }
}
*/
//链式存储

struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{
    struct Node *rear;
    struct Node *front;
};

typedef struct QNode *Queue;


ElementType Delet(Queue PtrQ)
{
    struct Node *FrontCell;
    ElementType FrontElem;
    if(PtrQ->front == NULL)
    {
        printf("队列空");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)
    {
        PtrQ->rear = PtrQ->front = NULL;
    }
    else {
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}